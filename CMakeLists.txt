cmake_minimum_required(VERSION 3.27)
project(Mesh_Viewer)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:/mingw_dev_lib/glfw-3.4/include")
link_directories("C:/mingw_dev_lib/glfw-3.4/lib-mingw-w64")

include_directories("C:/mingw_dev_lib/glm-1.0.1")
add_executable(Mesh_Viewer src/main.cpp
        src/glad.c
        header/stb_image.h
        header/Window.hpp
        src/Window.cpp
        src/Camera.hpp
        src/Camera.cpp
        src/Scene.hpp
        src/Mesh.hpp)
target_link_libraries(Mesh_Viewer glfw3)