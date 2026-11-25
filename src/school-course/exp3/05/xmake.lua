target("school-course-exp3-05-server")
    set_kind("binary")
    add_files("server.cpp", "../common/socket.cpp")
target_end()

target("school-course-exp3-05-client")
    set_kind("binary")
    add_files("client.cpp", "../common/socket.cpp")
target_end()

