# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
set(ARGE "ARGE")
set(ARGE_SRC "${${ARGE}_SOURCE_DIR}/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ARGE_SRC}/cmake/")

project ("ARGE")

find_package(OpenGL REQUIRED)

# Include sub-projects.
add_subdirectory(libs)

target_link_libraries(ARGE
	glfw
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
