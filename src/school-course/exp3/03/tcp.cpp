#include "tcp.h"

#include <unistd.h>


bool TcpServer::run(int port)
{
    int fd = acceptClient(port);
    if (-1 == fd) return false;

    // 通过接口引用动态分派，不依赖具体的 Echo 类型。
    bool result = m_observer.handle(fd);
    close(fd);


    return result;
}

bool TcpClient::run(int port)
{
    int fd = connectServer(port);
    if (-1 == fd) return false;

    // 通过接口引用动态分派，不依赖具体的 Echo 类型。
    bool result = m_observer.handle(fd);
    close(fd);


    return result;
}
