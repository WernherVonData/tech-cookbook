add_rules("mode.release")
set_languages("c++23")
set_warnings("all")

add_requires("sfml ~2.6.1", "tracy", "plog")

target("locality-of-reference")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("sfml", "tracy", "plog")
    add_defines("TRACY_ENABLE")