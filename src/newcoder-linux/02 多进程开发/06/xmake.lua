target("newcoder-linux-02-06-fpathconf")
    set_kind("binary")
    add_files("fpathconf.cpp")
target_end()

target("newcoder-linux-02-06-nonblock")
    set_kind("binary")
    add_files("nonblock.cpp")
target_end()

target("newcoder-linux-02-06-pipe")
    set_kind("binary")
    add_files("pipe.cpp")
target_end()

target("newcoder-linux-02-06-ps_grep")
    set_kind("binary")
    add_files("ps_grep.cpp")
target_end()

includes("*/xmake.lua")
