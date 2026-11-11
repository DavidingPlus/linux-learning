target("newcoder-linux-02-09-mmap_anon")
    set_kind("binary")
    add_files("mmap_anon.cpp")
target_end()

target("newcoder-linux-02-09-mmap_parent_child_ipc")
    set_kind("binary")
    add_files("mmap_parent_child_ipc.cpp")
target_end()

target("newcoder-linux-02-09-mmap_r_ipc")
    set_kind("binary")
    add_files("mmap_r_ipc.cpp")
target_end()

target("newcoder-linux-02-09-mmap_w_ipc")
    set_kind("binary")
    add_files("mmap_w_ipc.cpp")
target_end()

includes("*/xmake.lua")
