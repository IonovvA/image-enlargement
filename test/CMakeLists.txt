create_executable_project(test)

include_directories("../StaticLib")

target_link_libraries(test StaticLib)