target("school-course-exp3-03-server")
    set_kind("binary")
    add_files("server.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

target("school-course-exp3-03-client")
    set_kind("binary")
    add_files("client.cpp", "../common/socket.cpp", "tcp.cpp")
target_end()

