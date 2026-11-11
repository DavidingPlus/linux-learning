target("unix-apue-04-10-readlink")
    set_kind("binary")
    add_files("readlink.cpp")
target_end()

target("unix-apue-04-10-symlink")
    set_kind("binary")
    add_files("symlink.cpp")
target_end()
