target("unix-apue-05-02-line_buffer")
    set_kind("binary")
    add_files("line_buffer.cpp")
target_end()

target("unix-apue-05-02-setbuf_fbuf")
    set_kind("binary")
    add_files("setbuf_fbuf.cpp")
target_end()

target("unix-apue-05-02-setbuf_lbuf")
    set_kind("binary")
    add_files("setbuf_lbuf.cpp")
target_end()

target("unix-apue-05-02-setbuf_nbuf")
    set_kind("binary")
    add_files("setbuf_nbuf.cpp")
target_end()
