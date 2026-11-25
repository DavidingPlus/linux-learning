#include "tcp.h"

#include <unistd.h>


bool runServer(int port, ConnectionHandler handler)
{
    int fd = acceptClient(port);
    if (-1 == fd) return false;

    // 连接建立后才调用处理函数，随后由当前函数关闭描述符。
    bool result = handler(fd);
    close(fd);


    return result;
}

bool runClient(int port, ConnectionHandler handler)
{
    int fd = connectServer(port);
    if (-1 == fd) return false;

    // 连接建立后才调用处理函数，随后由当前函数关闭描述符。
    bool result = handler(fd);
    close(fd);


    return result;
}
