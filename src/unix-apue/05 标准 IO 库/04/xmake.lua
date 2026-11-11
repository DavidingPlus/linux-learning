target("unix-apue-05-04-getc")
    set_kind("binary")
    add_files("getc.cpp")
target_end()

target("unix-apue-05-04-putc")
    set_kind("binary")
    add_files("putc.cpp")
target_end()

target("unix-apue-05-04-ungetc")
    set_kind("binary")
    add_files("ungetc.cpp")
target_end()
