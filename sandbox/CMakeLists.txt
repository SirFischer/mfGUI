
cmake_minimum_required(VERSION 3.22.1)

project(Sandbox)

##FILES##
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.hpp)
#########


set(CMAKE_BUILD_TYPE Debug)


add_executable(Sandbox ${sources} )

set_target_properties(Sandbox PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(Sandbox PUBLIC cxx_std_17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

set_target_properties(PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(Sandbox PUBLIC sfml-graphics sfml-window ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libMFGUId.a)


target_include_directories(Sandbox PUBLIC
						"${PROJECT_BINARY_DIR}"
						"${PROJECT_SOURCE_DIR}/lib"
						"../include"
						"${CMAKE_CURRENT_SOURCE_DIR}/../lib"
)
