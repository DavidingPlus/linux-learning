#include "tcp.h"


// 将 echoServer 函数指针传入结构化服务端流程。
int main()
{
    return runServer(25200, echoServer) ? 0 : 1;
}
