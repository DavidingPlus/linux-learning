target("newcoder-linux-04-05-udp-UDP-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-05-udp-UDP-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
