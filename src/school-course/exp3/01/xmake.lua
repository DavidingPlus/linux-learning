target("school-course-exp3-01-server")
    set_kind("binary")
    add_files("server.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

target("school-course-exp3-01-client")
    set_kind("binary")
    add_files("client.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

