create_executable_project(Image)

include_directories("../StaticLib")

target_link_libraries(Image StaticLib)

