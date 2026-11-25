#ifndef _TCP_H_
#define _TCP_H_

#include "../common/socket.h"


// 观察者接口只规定已连接 socket 的处理方式，不负责建立连接。
class ConnectionObserver
{

public:

    virtual ~ConnectionObserver() = default;

    // 服务端和客户端的 Echo 对象分别实现这个接口。
    virtual bool handle(int fd) = 0;
};


class TcpServer
{

public:

    // 保存观察者引用；观察者必须比 TcpServer 活得更久。
    explicit TcpServer(ConnectionObserver &observer) : m_observer(observer) {}

    bool run(int port);


private:

    // 引用不拥有观察者，生命周期由调用方管理。
    ConnectionObserver &m_observer;
};


// 客户端也依赖同一接口，可注入不同的连接处理对象。
class TcpClient
{

public:

    explicit TcpClient(ConnectionObserver &observer) : m_observer(observer) {}

    bool run(int port);


private:

    // 引用不拥有观察者，生命周期由调用方管理。
    ConnectionObserver &m_observer;
};


#endif
