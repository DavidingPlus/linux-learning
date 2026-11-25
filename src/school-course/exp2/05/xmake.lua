target("school-course-exp2-05")
    set_kind("binary")
    add_files("*.cpp")

    before_build(function (target)
        os.mkdir(target:targetdir())
        os.cp(path.join(os.scriptdir(), "school-course-exp2-05-config.txt"), target:targetdir())
    end)
target_end()
