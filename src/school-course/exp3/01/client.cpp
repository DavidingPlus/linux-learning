#include "tcp.h"


// 将 echoClient 函数指针传入结构化客户端流程。
int main()
{
    return runClient(25200, echoClient) ? 0 : 1;
}
