target("unix-apue-01-01_dir")
    set_kind("binary")
    add_files("01_dir.cpp")
target_end()

target("unix-apue-01-02_stdin_stdout")
    set_kind("binary")
    add_files("02_stdin_stdout.cpp")
target_end()

target("unix-apue-01-03_getc_putc")
    set_kind("binary")
    add_files("03_getc_putc.cpp")
target_end()

target("unix-apue-01-04_exec")
    set_kind("binary")
    add_files("04_exec.cpp")
target_end()

target("unix-apue-01-05_err")
    set_kind("binary")
    add_files("05_err.cpp")
target_end()

target("unix-apue-01-06_uidgid")
    set_kind("binary")
    add_files("06_uidgid.cpp")
target_end()

target("unix-apue-01-07_sigaction")
    set_kind("binary")
    add_files("07_sigaction.cpp")
target_end()
