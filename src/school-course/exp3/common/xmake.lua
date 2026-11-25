target("school-course-exp3-test")
    set_kind("phony")
    add_values("test.script", path.join(os.scriptdir(), "test.py"))
    for i = 1, 5 do
        add_deps(string.format("school-course-exp3-%02d-server", i))
        add_deps(string.format("school-course-exp3-%02d-client", i))
    end
    on_run(function (target)
        local args = {target:values("test.script")}
        for i = 1, 5 do
            table.insert(args, target:dep(string.format("school-course-exp3-%02d-server", i)):targetfile())
            table.insert(args, target:dep(string.format("school-course-exp3-%02d-client", i)):targetfile())
        end
        os.execv("python3", args)
    end)
target_end()
