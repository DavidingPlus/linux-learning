local projectdir = os.scriptdir()

target("school-course-exp1-04")
    set_kind("binary")
    set_targetdir(projectdir)

    on_build(function ()
        os.vrunv("make", {}, {curdir = projectdir})
    end)
    on_clean(function ()
        os.vrunv("make", {"clean"}, {curdir = projectdir})
    end)
target_end()
