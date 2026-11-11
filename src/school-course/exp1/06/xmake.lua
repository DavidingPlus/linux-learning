add_requires("gtest")


target("school-course-exp1-06")
    set_kind("binary")
    set_languages("cxx17")
    add_files("*.cpp")
    add_packages("gtest")
target_end()
