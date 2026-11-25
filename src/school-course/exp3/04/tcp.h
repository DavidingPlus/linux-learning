#ifndef _TCP_H_
#define _TCP_H_

#include "../common/socket.h"

#include <unistd.h>


// CRTP：派生类把自身作为模板参数传给服务端基类。基类由此在编译期获知业务处理类的具体类型。
template <typename Derived>
class TcpServer
{

public:

    bool run(int port);
};


// 客户端也使用 CRTP；它的 Derived 实现客户端收发逻辑。
template <typename Derived>
class TcpClient
{

public:

    bool run(int port);
};


template <typename Derived>
bool TcpServer<Derived>::run(int port)
{
    int fd = acceptClient(port);
    if (-1 == fd) return false;

    // this 指向 Derived 对象中的基类子对象，转换后调用派生类的 handle。此调用不使用虚函数表，handle 需要对基类可访问。
    bool result = static_cast<Derived *>(this)->handle(fd);
    close(fd);


    return result;
}

template <typename Derived>
bool TcpClient<Derived>::run(int port)
{
    int fd = connectServer(port);
    if (-1 == fd) return false;

    bool result = static_cast<Derived *>(this)->handle(fd);
    close(fd);


    return result;
}


#endif
