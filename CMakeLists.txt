cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE LEGACY)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main
	src/main.cpp
	src/Application.cpp
	src/Camera.cpp
	src/Scene.cpp
	src/OBJModel.cpp
	src/Transform.cpp
	src/Renderer.cpp
	src/objects/Chair.cpp
	src/objects/Blinds.cpp
	src/objects/Bed.cpp
	src/objects/Desk.cpp
	src/objects/Dresser.cpp
	src/objects/Lamp.cpp
	src/objects/Shelf.cpp
	src/objects/Clock.cpp
	src/objects/Apple.cpp
	src/objects/Room.cpp
)

target_include_directories(main PRIVATE include include/objects)
target_link_libraries(main PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
