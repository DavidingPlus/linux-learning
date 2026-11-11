target("newcoder-linux-04-04-poll-client")
    set_kind("binary")
    add_files("client.cpp")
target_end()

target("newcoder-linux-04-04-poll-server")
    set_kind("binary")
    add_files("server.cpp")
target_end()
