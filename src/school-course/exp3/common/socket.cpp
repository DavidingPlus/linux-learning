#include "socket.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <string>


// 客户端只连接本机回环地址，避免实验服务暴露到外网。调用方负责在通信结束后关闭返回的描述符。
int connectServer(int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == fd)
    {
        std::perror("socket");
        return -1;
    }

    sockaddr_in address = {};
    address.sin_family = AF_INET;
    // 端口号和 IPv4 地址都要转换为网络字节序。
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (-1 == connect(fd, reinterpret_cast<sockaddr *>(&address), sizeof(address)))
    {
        std::perror("connect");
        close(fd);
        return -1;
    }


    return fd;
}

// 服务端仅接受一个连接；监听描述符在 accept 后立即关闭。已连接描述符仍可独立用于后续数据传输。
int acceptClient(int port)
{
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == listener)
    {
        std::perror("socket");
        return -1;
    }

    // 允许程序结束后快速重新绑定同一监听端口。
    int reuse = 1;
    if (-1 == setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)))
    {
        std::perror("setsockopt");
        close(listener);
        return -1;
    }

    sockaddr_in address = {};
    address.sin_family = AF_INET;
    // 端口号和 IPv4 地址都要转换为网络字节序。
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    // bind 指定本地端点，listen 使套接字进入被动监听状态。
    if (-1 == bind(listener, reinterpret_cast<sockaddr *>(&address), sizeof(address)) || -1 == listen(listener, 1))
    {
        std::perror("bind/listen");
        close(listener);
        return -1;
    }

    std::cerr << "listening on 127.0.0.1:" << port << '\n';
    int fd;
    // 系统调用被信号中断时重试，而不是误判为连接失败。
    do
    {
        fd = accept(listener, nullptr, nullptr);
    } while (-1 == fd && EINTR == errno);

    if (-1 == fd) std::perror("accept");
    close(listener);


    return fd;
}

// TCP 的一次 send 可能只发送部分数据，需要推进指针继续发送。MSG_NOSIGNAL 使对端关闭时返回错误，而不是触发 SIGPIPE。
bool sendAll(int fd, const char *data, size_t size)
{
    while (size > 0)
    {
        ssize_t count = send(fd, data, size, MSG_NOSIGNAL);
        if (-1 == count && EINTR == errno) continue;
        if (count <= 0)
        {
            std::perror("send");
            return false;
        }

        data += count;
        size -= count;
    }


    return true;
}

// 服务端不解释消息内容，只把每次收到的字节原样发回。recv 返回 0 表示客户端已关闭连接，结束当前实验。
bool echoServer(int fd)
{
    char buffer[1024];
    for (;;)
    {
        ssize_t count = recv(fd, buffer, sizeof(buffer), 0);
        if (-1 == count && EINTR == errno) continue;
        if (-1 == count)
        {
            std::perror("recv");
            return false;
        }
        if (0 == count) return true;

        if (!sendAll(fd, buffer, static_cast<size_t>(count))) return false;
    }
}

// 客户端按行读取输入，分块发送并逐块收齐回显。先收完当前块再发送下一块，避免双方因缓冲区满而互相等待。
bool echoClient(int fd)
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        // getline 丢弃分隔符；仅在实际读到换行时补回。
        if (!std::cin.eof()) line += '\n';
        for (size_t pos = 0; pos < line.size();)
        {
            size_t size = std::min(size_t(1024), line.size() - pos);
            if (!sendAll(fd, line.data() + pos, size)) return false;

            // TCP 不保证一次 recv 收到完整的发送块。
            size_t received = 0;
            while (received < size)
            {
                char buffer[1024];
                ssize_t count = recv(fd, buffer, size - received, 0);
                if (-1 == count && EINTR == errno) continue;
                if (count <= 0)
                {
                    if (-1 == count)
                        std::perror("recv");
                    else
                        std::cerr << "server closed the connection early\n";
                    return false;
                }
                // 按实际字节数输出，不依赖字符串终止符。
                std::cout.write(buffer, count);
                received += static_cast<size_t>(count);
            }

            std::cout.flush();
            if (!std::cout) return false;
            pos += size;
        }
    }


    return !std::cin.bad();
}
