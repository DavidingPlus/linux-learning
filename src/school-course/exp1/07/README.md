# 实验：使用 Valgrind 检测内存问题

## 程序说明

`main.cpp` 动态分配包含 5 个整数的数组，通过命令行参数选择三种模式：

| 参数 | 程序行为 | 预期检测结果 |
| --- | --- | --- |
| `clean` | 读取 `values[0]`，随后用 `delete[]` 释放数组 | 无泄漏，无内存访问错误 |
| `leak` | 读取 `values[0]`，故意不释放数组 | 报告确定的内存泄漏 |
| `invalid` | 故意读取越界的 `values[5]`，随后释放数组 | 报告非法读取，无内存泄漏 |

`leak` 和 `invalid` 是为了演示而故意编写的错误。数组合法下标为 0 到 4；越界读取属于未定义行为，显示出的数值不可靠，也可能导致程序异常退出。

## 编译

需要 Linux、C++ 编译器和 Valgrind。如果尚未安装 Valgrind，可在 Ubuntu / Debian 上使用 `sudo apt install valgrind` 安装。

在项目根目录执行：

```sh
xmake build school-course-exp1-07
```

xmake 目标包含 `-g -O0`，便于报告源文件和行号。也可以直接编译到固定路径，以下检测步骤使用此路径：

```sh
g++ -g -O0 src/school-course/exp1/07/main.cpp -o /tmp/valgrind-demo
```

## 检测及截图步骤

1. 检测正常程序：

   ```sh
   valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=99 /tmp/valgrind-demo clean
   ```

   观察 `All heap blocks were freed` 和 `ERROR SUMMARY: 0 errors`。**截图 1：正常模式的堆摘要和错误摘要。**

2. 检测内存泄漏：

   ```sh
   valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=99 /tmp/valgrind-demo leak
   ```

   观察 `definitely lost`，本次实测报告 1 个内存块共 20 字节泄漏，并给出数组分配处的源码行号。**截图 2：泄漏位置和 `LEAK SUMMARY`。**

3. 检测指针访问违规：

   ```sh
   valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=99 /tmp/valgrind-demo invalid
   ```

   观察 `Invalid read of size 4` 及其源码行号；报告还指出访问位置刚好在分配区域之后。**截图 3：非法读取及错误摘要。**

`--leak-check=full` 显示详细泄漏信息，`--show-leak-kinds=all` 展示各类泄漏，`--error-exitcode=99` 在检测到错误时返回 99；因此后两个命令返回非零状态是预期结果。实际大小、地址、PID 和行号可能因环境或代码修改而变化。

## 结果分析

三个模式使用同一份程序，分别对比了正确释放、未释放和越界访问。正常模式没有检测到问题；泄漏模式分配后丢失了内存块；非法访问模式虽然释放了内存，但仍然发生了越界读取。这说明“没有内存泄漏”并不代表“没有内存访问错误”。

实际检测输出分别保存在 [正常模式](valgrind-clean.txt)、[泄漏模式](valgrind-leak.txt) 和 [非法访问模式](valgrind-invalid.txt)。Valgrind 只能检查当前执行路径中实际发生的问题，不能证明程序在所有输入下都没有内存错误。

