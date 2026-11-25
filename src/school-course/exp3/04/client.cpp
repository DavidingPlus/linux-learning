#include "tcp.h"


// Echo 将自身传给 TcpClient，供基类静态调用 handle。
class Echo : public TcpClient<Echo>
{

public:

    bool handle(int fd) { return echoClient(fd); }
};


int main()
{
    Echo echo;
    return echo.run(25230) ? 0 : 1;
}
