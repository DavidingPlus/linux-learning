#include "tcp.h"


// 服务端 Echo 实现观察者接口，再注入 TcpServer。
class Echo : public ConnectionObserver
{

public:

    bool handle(int fd) override { return echoServer(fd); }
};


int main()
{
    Echo echo;
    TcpServer tcp(echo);
    return tcp.run(25220) ? 0 : 1;
}
