# 实验三：TCP Socket 通信库封装

五个目录分别实现结构化函数指针、面向对象虚函数、接口观察者、CRTP 静态多态和模板处理器五种封装。公共的 socket 建连和 echo 收发声明在 `common/socket.h`，实现在 `common/socket.cpp`；每组的 `tcp.h` 声明对应的封装；01–03 的实现在 `tcp.cpp`，04–05 的模板实现在各自的 `tcp.h` 中。

每组各有独立的服务端和客户端，端口依次为 25200、25210、25220、25230、25240，只监听本机回环地址。先编译，再在两个终端分别运行，例如第一组：

```bash
xmake build school-course-exp3-01-server
xmake build school-course-exp3-01-client
xmake run school-course-exp3-01-server
# 在另一个终端：
xmake run school-course-exp3-01-client
```

客户端输入一行后按回车，服务端显示收到的字节并原样返回，客户端显示回显结果；继续输入可多次测试，按 Ctrl+D 结束输入。服务端处理一个客户端后退出，需要重新测试时重新启动。其余四组将目标名中的 `01` 改为 `02` 至 `05`。

使用下面的命令通过 xmake 编译并验证全部五组（需要 Python 3）：

```bash
xmake run school-course-exp3-test
```
