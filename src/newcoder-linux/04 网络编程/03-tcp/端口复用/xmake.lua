target("newcoder-linux-04-03-tcp-端口复用-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-03-tcp-端口复用-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
