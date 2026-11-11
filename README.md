# linux-learning

Linux 方向的学习，里面包含了不同课程的学习和书籍的学习。

学习内容按主题存放在 src 目录下：

- src/newcoder-linux：牛客 Linux 课程的学习。课程链接：[https://www.nowcoder.com/courses/cover/live/504](https://www.nowcoder.com/courses/cover/live/504)

- src/unix-apue：《UNIX 环境高级编程》书籍的阅读和学习。

- src/tcp-ip：《TCP IP 网络编程》书籍的阅读和学习。

- src/school-course：校内课程实验，包含 Linux 环境高级编程实验。

markdown 文档笔记下载地址：[https://github.com/DavidingPlus/study-notes](https://github.com/DavidingPlus/study-notes)

## 编译与运行

在 Linux 上安装 xmake、C/C++ 编译器和 pthread 开发环境后，在项目根目录执行：

```sh
xmake                         # 编译全部示例
xmake show -l targets         # 查看所有目标
xmake build tcp-ip-03-byte_order
xmake run tcp-ip-03-byte_order
xmake run tcp-ip-01-hello_server 9190  # 向程序传递参数
xmake run school-course-exp1-06         # 运行 GoogleTest 测试
```

目标名由主题、章节编号、其余子目录和源文件名组成，各部分以 `-` 分隔，保留源文件名中的下划线；如果文件名和上一级目录同名，则只保留一次。例如 `src/newcoder-linux/01 Linux 开发环境搭建/01/01.cpp` 对应 `newcoder-linux-01-01`，`src/tcp-ip/03/byte_order.cpp` 对应 `tcp-ip-03-byte_order`。各级 `xmake.lua` 逐级引入子目录，具体目标定义在示例所在目录；新增示例时需要在该目录的 `xmake.lua` 中添加目标。

部分示例需要命令行参数、输入文件、配套客户端或服务端，运行前请查看对应源码；相对路径以运行时的工作目录为准。仓库内的 Redis 源码使用其自身的构建系统，不包含在这些目标中。

校内课程实验位于 `src/school-course/exp1`：`04` 使用 Makefile 构建，`05` 演示 GDB 多进程调试，`06` 使用 GoogleTest，`07` 演示 Valgrind 内存检测。`04` 的 xmake 目标会调用 Makefile；GoogleTest 由 xmake 管理，缺少依赖时可能需要下载安装。`05` 和 `07` 的复现步骤见各自目录下的 README。

