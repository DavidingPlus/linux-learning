target("newcoder-linux-04-05-udp-Broadcast-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-05-udp-Broadcast-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
