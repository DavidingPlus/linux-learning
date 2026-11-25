#include "tcp.h"


// Echo 仅定义服务端业务，由 TcpServer 模板继承并调用。
class Echo
{
public:

    bool handle(int fd) { return echoServer(fd); }
};


int main()
{
    TcpServer<Echo> tcp;
    return tcp.run(25240) ? 0 : 1;
}
