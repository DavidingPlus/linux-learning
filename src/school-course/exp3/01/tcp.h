#ifndef _TCP_H_
#define _TCP_H_

#include "../common/socket.h"


// 函数指针接收已连接的 socket，返回业务是否成功。连接管理函数不需要知道具体处理函数的名称。
typedef bool (*ConnectionHandler)(int);


// 服务端通过传入的 handler 执行 echo 业务。
bool runServer(int port, ConnectionHandler handler);

// 客户端复用相同的函数指针类型，但由调用者传入客户端处理函数。
bool runClient(int port, ConnectionHandler handler);


#endif
