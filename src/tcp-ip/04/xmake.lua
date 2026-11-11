target("tcp-ip-04-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("tcp-ip-04-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
