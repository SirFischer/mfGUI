
cmake_minimum_required(VERSION 3.22.1)

project(Sandbox)

##FILES##
file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.hpp)
#########


set(CMAKE_BUILD_TYPE Debug)


# Add custom command to run ninja in the parent directory
add_custom_command(OUTPUT update_library
                   COMMAND cd .. && ninja
                   COMMENT "Updating library using Ninja")


# Add custom target that depends on the above command
add_custom_target(UpdateLibrary DEPENDS update_library)

add_executable(Sandbox ${sources} )

# Make Sandbox target depend on the custom target
add_dependencies(Sandbox UpdateLibrary)

set_target_properties(Sandbox PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(Sandbox PUBLIC cxx_std_17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

set_target_properties(PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(Sandbox PUBLIC sfml-graphics sfml-window sfml-system ${CMAKE_CURRENT_SOURCE_DIR}/../lib/libMFGUId.a)


target_include_directories(Sandbox PUBLIC
						"${PROJECT_BINARY_DIR}"
						"${PROJECT_SOURCE_DIR}/lib"
						"../include"
						"${CMAKE_CURRENT_SOURCE_DIR}/../lib"
)
