target("tcp-ip-01-hello_client")
    set_kind("binary")
    add_files("hello_client.cpp")
target_end()

target("tcp-ip-01-hello_server")
    set_kind("binary")
    add_files("hello_server.cpp")
target_end()
