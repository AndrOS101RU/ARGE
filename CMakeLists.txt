cmake_minimum_required (VERSION 3.2)
project ("ARGE")

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

set(SRC "${ARGE_SOURCE_DIR}/")

file(GLOB_RECURSE SOURCE
  "${SRC}source/*.cpp"
  "${SRC}include/*.hpp"
)

add_subdirectory(
	libs
)

include_directories(
	libs/
	include/
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_library(GLAD STATIC
  libs/glad/glad.c
)

add_executable(ARGE ${SOURCE})

source_group(TREE ${SRC} FILES ${SOURCE})

target_precompile_headers(ARGE PUBLIC
	"${SRC}include/ARGE/pch.hpp"
)

target_include_directories(ARGE PUBLIC 
	libs/glfw/include
	include
)

target_link_libraries(ARGE
	${OPENGL_LIBRARY}
    ${GLFW_LIBRARIES}
	glfw
	GLAD
)