
cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_CXX_STANDARD 17)

project(Sandbox)

##FILES##
file(GLOB_RECURSE sources src/*.cpp src/*.hpp)
#########

add_subdirectory(.. lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)


add_executable(Sandbox ${sources} )


target_link_libraries(Sandbox PUBLIC MFGUI sfml-graphics)


target_include_directories(Sandbox PUBLIC
						"${PROJECT_BINARY_DIR}"
						"${PROJECT_SOURCE_DIR}/lib"
)
