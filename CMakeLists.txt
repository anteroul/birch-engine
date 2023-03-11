cmake_minimum_required(VERSION 3.16)
project(BirchEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARY_DIRS})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARY_DIRS})

add_executable(BirchEngine src/entrypoint/main.cpp src/Engine.cpp src/Engine.h lib/stb_image.h src/Transform.h src/Camera.cpp src/Cube.cpp src/Material.cpp src/ObjLoader.cpp src/Mesh.cpp src/Scene.cpp src/Window.cpp src/Transform.cpp src/Texture.cpp src/Shader.cpp)

target_link_libraries(BirchEngine ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES})