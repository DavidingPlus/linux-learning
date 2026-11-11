target("newcoder-linux-02-04-exit-_exit")
    set_kind("binary")
    add_files("exit-_exit.cpp")
target_end()

target("newcoder-linux-02-04-orphan")
    set_kind("binary")
    add_files("orphan.cpp")
target_end()

target("newcoder-linux-02-04-zombie")
    set_kind("binary")
    add_files("zombie.cpp")
target_end()
