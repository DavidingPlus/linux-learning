#include "tcp.h"


// Echo 仅定义客户端业务，由 TcpClient 模板继承并调用。
class Echo
{
public:

    bool handle(int fd) { return echoClient(fd); }
};


int main()
{
    TcpClient<Echo> tcp;
    return tcp.run(25240) ? 0 : 1;
}
