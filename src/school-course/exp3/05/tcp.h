#ifndef _TCP_H_
#define _TCP_H_

#include "../common/socket.h"

#include <unistd.h>


// 将业务处理类作为模板参数，通信模板继承该处理类。业务类不用反向继承 TcpServer，替换 Handler 即可更换业务。
template <typename Handler>
class TcpServer : public Handler
{

public:

    bool run(int port);
};


// 客户端模板同样继承处理器，但使用客户端自己的 Echo 类型。
template <typename Handler>
class TcpClient : public Handler
{

public:

    bool run(int port);
};


template <typename Handler>
bool TcpServer<Handler>::run(int port)
{
    int fd = acceptClient(port);
    if (-1 == fd) return false;

    // handle 来自依赖模板参数的基类，因此使用 this-> 查找。通信流程与业务处理在模板实例化时组合。
    bool result = this->handle(fd);
    close(fd);


    return result;
}

template <typename Handler>
bool TcpClient<Handler>::run(int port)
{
    int fd = connectServer(port);
    if (-1 == fd) return false;

    bool result = this->handle(fd);
    close(fd);


    return result;
}


#endif
