#include "tcp.h"


// 客户端 Echo 实现观察者接口，再注入 TcpClient。
class Echo : public ConnectionObserver
{

public:

    bool handle(int fd) override { return echoClient(fd); }
};


int main()
{
    Echo echo;
    TcpClient tcp(echo);
    return tcp.run(25220) ? 0 : 1;
}
