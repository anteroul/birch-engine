cmake_minimum_required(VERSION 3.16)
project(BirchEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

add_executable(BirchEngine src/entrypoint/main.cpp src/Engine.cpp src/Engine.h src/Object.h src/Object.cpp)

target_link_libraries(BirchEngine ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES} glfw)