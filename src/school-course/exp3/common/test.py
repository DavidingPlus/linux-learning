#!/usr/bin/env python3
"""通过本机回环地址验证 xmake 构建的五组 echo 程序。"""

import subprocess
import sys

if 11 != len(sys.argv):
    raise SystemExit("需要依次传入五组服务端和客户端程序的路径")

for step in range(1, 6):
    server, client = sys.argv[2 * step - 1:2 * step + 1]
    for name, data in (("多行文本", b"hello with spaces\n\nsecond line\n"),
                       ("长文本及末尾无换行", b"x" * 100000 + b"\nlast line"),
                       ("空输入", b"")):
        print(f"第 {step:02} 组 - {name}: 运行中", flush=True)
        with subprocess.Popen([server], stderr=subprocess.PIPE) as process:
            assert b"listening" in process.stderr.readline(), "server did not start"
            result = subprocess.run(
                [client], input=data, capture_output=True, timeout=10, check=True)
            assert result.stdout == data, f"step {step}: incorrect echo"
            assert 0 == process.wait(timeout=10), f"step {step}: server failed"
        print(f"第 {step:02} 组 - {name}: 通过", flush=True)
