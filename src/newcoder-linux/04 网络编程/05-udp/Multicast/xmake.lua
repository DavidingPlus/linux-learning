target("newcoder-linux-04-05-udp-Multicast-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-05-udp-Multicast-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
