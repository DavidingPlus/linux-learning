target("newcoder-linux-04-06-ipc-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-06-ipc-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
