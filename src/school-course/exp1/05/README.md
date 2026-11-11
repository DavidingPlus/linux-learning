# 使用 GDB 调试多进程

## 程序说明

`main.cpp` 使用 `fork()` 创建子进程。子进程在 `childWork()` 中将变量 `value` 从 10 加到 15；父进程通过 `waitpid()` 等待并回收子进程。程序分别输出父、子进程的 PID，父进程还会输出子进程的退出状态。

## 编译和运行

在项目根目录执行，需要 Linux、xmake、C++ 编译器和 GDB：

```sh
xmake build school-course-exp1-05
xmake run school-course-exp1-05
```

目标已启用调试信息并关闭优化。也可以直接编译并调试：

```sh
g++ -g -O0 src/school-course/exp1/05/main.cpp -o /tmp/multiprocess
```

## 调试及截图步骤

1. 在项目根目录启动 GDB：

   ```sh
   gdb -q /tmp/multiprocess
   ```

   如果使用 xmake 编译，可将 `/tmp/multiprocess` 换为对应的构建产物路径，例如 Linux x86_64 debug 模式下的 `build/linux/x86_64/debug/school-course-exp1-05`。

2. 在 `(gdb)` 提示符下逐行输入：

   ```gdb
   set disable-randomization off
   set follow-fork-mode child
   set detach-on-fork off
   break childWork
   run
   ```

   这会让 GDB 在 `fork()` 后跟踪子进程，同时保留对父进程的控制。程序在子进程的 `childWork()` 处停下。**截图 1：断点和子进程停下的位置。**

3. 查看被调试的进程：

   ```gdb
   info inferiors
   ```

   列表中包含父、子进程，`*` 标记当前选中的子进程。`Num` 是 GDB 的进程编号，`process` 后是操作系统 PID，两者不同。**截图 2：父、子进程列表。**

4. 单步执行并查看变量：

   ```gdb
   next
   print value
   next
   print value
   ```

   两次输出分别为 10 和 15。`next` 执行当前源代码行，`print` 查看变量值。**截图 3：变量值变化。**

5. 先让子进程退出，再切回父进程继续运行：

   ```gdb
   continue
   inferior 1
   continue
   quit
   ```

   `inferior 1` 中的编号应以第 3 步的父进程编号为准。父进程恢复后，通过 `waitpid()` 回收子进程并输出退出状态。**截图 4：两个进程正常退出的结果。** 如果先运行父进程，它可能在 `waitpid()` 等待仍被 GDB 暂停的子进程。

实际调试输出见 [gdb-output.txt](gdb-output.txt)。PID 和地址会随运行变化。切换父进程时如果提示系统库源文件不存在，不影响继续执行本例。

