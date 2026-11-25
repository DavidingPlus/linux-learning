#ifndef _TCP_H_
#define _TCP_H_

#include "../common/socket.h"


// 服务端基类管理连接，派生类通过虚函数决定连接后的行为。
class TcpServer
{

public:

    // 基类含虚函数，虚析构允许安全地通过基类指针销毁派生对象。
    virtual ~TcpServer() = default;

    bool run(int port);


private:

    virtual bool handle(int fd) = 0;
};


// 客户端同样通过继承扩展业务，连接流程留在基类。
class TcpClient
{

public:

    virtual ~TcpClient() = default;

    bool run(int port);


private:

    virtual bool handle(int fd) = 0;
};


#endif
