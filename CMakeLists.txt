cmake_minimum_required (VERSION 3.2)
project ("ARGE")

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

add_subdirectory(libs)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(libs)

add_executable (ARGE "source/ARGE/ARGE.cpp" "source/ARGE/ARGE.h")

target_include_directories(ARGE PUBLIC libs/glfw/include)