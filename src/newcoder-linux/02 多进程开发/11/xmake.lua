target("newcoder-linux-02-11-sigaction")
    set_kind("binary")
    add_files("sigaction.cpp")
target_end()

target("newcoder-linux-02-11-sigchld")
    set_kind("binary")
    add_files("sigchld.cpp")
target_end()

target("newcoder-linux-02-11-sigprocmask")
    set_kind("binary")
    add_files("sigprocmask.cpp")
target_end()

target("newcoder-linux-02-11-sigset")
    set_kind("binary")
    add_files("sigset.cpp")
target_end()
