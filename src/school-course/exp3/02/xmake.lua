target("school-course-exp3-02-server")
    set_kind("binary")
    add_files("server.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

target("school-course-exp3-02-client")
    set_kind("binary")
    add_files("client.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

