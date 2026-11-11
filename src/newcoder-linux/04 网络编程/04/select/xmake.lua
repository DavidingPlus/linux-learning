target("newcoder-linux-04-04-select-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-04-select-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
