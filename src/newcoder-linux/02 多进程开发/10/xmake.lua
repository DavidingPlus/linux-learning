target("newcoder-linux-02-10-alarm")
    set_kind("binary")
    add_files("alarm.cpp")
target_end()

target("newcoder-linux-02-10-alarm_example")
    set_kind("binary")
    add_files("alarm_example.cpp")
target_end()

target("newcoder-linux-02-10-core")
    set_kind("binary")
    add_files("core.cpp")
target_end()

target("newcoder-linux-02-10-kill")
    set_kind("binary")
    add_files("kill.cpp")
target_end()

target("newcoder-linux-02-10-setitimer")
    set_kind("binary")
    add_files("setitimer.cpp")
target_end()

target("newcoder-linux-02-10-signal")
    set_kind("binary")
    add_files("signal.cpp")
target_end()
