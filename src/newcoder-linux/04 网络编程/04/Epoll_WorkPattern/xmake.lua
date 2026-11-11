target("newcoder-linux-04-04-Epoll_WorkPattern-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-04-Epoll_WorkPattern-epoll_et")
    set_kind("binary")
    add_files("epoll_et.cpp")
target_end()

target("newcoder-linux-04-04-Epoll_WorkPattern-epoll_lt")
    set_kind("binary")
    add_files("epoll_lt.cpp")
target_end()
