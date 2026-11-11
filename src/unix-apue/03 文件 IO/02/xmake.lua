target("unix-apue-03-02-lseek")
    set_kind("binary")
    add_files("lseek.cpp")
target_end()

target("unix-apue-03-02-lseek_err")
    set_kind("binary")
    add_files("lseek_err.cpp")
target_end()
