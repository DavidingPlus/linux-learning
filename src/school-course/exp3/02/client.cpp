#include "tcp.h"


// Echo 继承客户端基类，通过重写 handle 提供收发行为。
class Echo : public TcpClient
{

private:

    bool handle(int fd) override { return echoClient(fd); }
};


int main()
{
    Echo echo;
    return echo.run(25210) ? 0 : 1;
}
