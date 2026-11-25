#include "tcp.h"

#include <unistd.h>


bool TcpServer::run(int port)
{
    int fd = acceptClient(port);
    if (-1 == fd) return false;

    // 此处发生动态分派，实际调用派生 Echo 类中的 handle。
    bool result = handle(fd);
    close(fd);


    return result;
}

bool TcpClient::run(int port)
{
    int fd = connectServer(port);
    if (-1 == fd) return false;

    // 此处发生动态分派，实际调用派生 Echo 类中的 handle。
    bool result = handle(fd);
    close(fd);


    return result;
}
