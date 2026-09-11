cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main
	src/main.cpp
	src/Application.cpp
	src/Camera.cpp
	src/Scene.cpp
	src/Cone.cpp
	src/OBJModel.cpp
)

target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
