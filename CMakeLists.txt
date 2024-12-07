cmake_minimum_required(VERSION 3.13.4)

project(MFGUI VERSION 0.1.0 DESCRIPTION "MFGUI is the Marek Fischer GUI library.")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_library(${PROJECT_NAME} STATIC)


##FILES##
file(GLOB_RECURSE sources src/*.cpp src/*.hpp include/*.hpp)
#########

target_sources(${PROJECT_NAME} PRIVATE ${sources})

find_package(SFML REQUIRED COMPONENTS graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})


if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")