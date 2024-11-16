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
        header/Camera.hpp
        header/Scene.hpp
        header/Mesh/Mesh.hpp
        header/Material.hpp
        header/Texture.hpp
        src/Camera.cpp
        src/Window.cpp
        src/Shader.cpp
        src/Texture.cpp
        src/Mesh/Mesh.cpp
        header/Mesh/HalfEdge.h
        src/Mesh/HalfEdge.cpp
        header/Mesh/Vertex.h
        header/Mesh/MeshTriangle.h
        src/Mesh/MeshTriangle.cpp
        src/Mesh/Vertex.cpp
        src/Mesh/Edge.cpp)
target_link_libraries(Mesh_Viewer glfw3)