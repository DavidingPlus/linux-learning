target("newcoder-linux-03-02-deadlock")
    set_kind("binary")
    add_files("deadlock.cpp")
target_end()

target("newcoder-linux-03-02-deadlock2")
    set_kind("binary")
    add_files("deadlock2.cpp")
target_end()

target("newcoder-linux-03-02-mutex")
    set_kind("binary")
    add_files("mutex.cpp")
target_end()

target("newcoder-linux-03-02-pthread_attr")
    set_kind("binary")
    add_files("pthread_attr.cpp")
target_end()

target("newcoder-linux-03-02-rwlock")
    set_kind("binary")
    add_files("rwlock.cpp")
target_end()

target("newcoder-linux-03-02-selltickets")
    set_kind("binary")
    add_files("selltickets.cpp")
target_end()
