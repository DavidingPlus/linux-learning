#include "tcp.h"


// Echo 继承服务端基类，通过重写 handle 提供回显行为。
class Echo : public TcpServer
{

private:

    bool handle(int fd) override { return echoServer(fd); }
};


int main()
{
    Echo echo;
    return echo.run(25210) ? 0 : 1;
}
