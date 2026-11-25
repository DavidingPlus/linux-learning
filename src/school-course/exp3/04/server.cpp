#include "tcp.h"


// Echo 将自身传给 TcpServer，供基类静态调用 handle。
class Echo : public TcpServer<Echo>
{

public:

    bool handle(int fd) { return echoServer(fd); }
};


int main()
{
    Echo echo;
    return echo.run(25230) ? 0 : 1;
}
