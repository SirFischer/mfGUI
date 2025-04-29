cmake_minimum_required(VERSION 3.13.4)

project(MFGUI VERSION 0.1.0 DESCRIPTION "MFGUI is the Marek Fischer GUI library.")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_library(${PROJECT_NAME} STATIC)


##FILES##
set(WIDGET_SOURCES
    src/widgets/Button.cpp
    src/widgets/Checkbox.cpp
    src/widgets/Container.cpp
    src/widgets/Image.cpp
    src/widgets/List.cpp
    src/widgets/Slider.cpp
    src/widgets/Text.cpp
)

set(WIDGET_COMPONENTS_SOURCES
    src/widgetComponents/Background.cpp
    src/widgetComponents/EventManager.cpp
    src/widgetComponents/ScrollBar.cpp
    src/widgetComponents/Text.cpp
)

set(CORE_SOURCES
    src/mfGUI.cpp
)

set(HEADERS
    include/mfGUI.hpp
    src/utils/Direction.hpp
    src/utils/Events.hpp
    src/widgetAttributes/Transform.hpp
    src/widgetComponents/Background.hpp
    src/widgetComponents/EventManager.hpp
    src/widgetComponents/ScrollBar.hpp
    src/widgetComponents/Text.hpp
    src/widgets/Button.hpp
    src/widgets/Checkbox.hpp
    src/widgets/Container.hpp
    src/widgets/Image.hpp
    src/widgets/List.hpp
    src/widgets/Slider.hpp
    src/widgets/Text.hpp
    src/widgets/Widget.hpp
)

set(ALL_SOURCES
    ${WIDGET_SOURCES}
    ${WIDGET_COMPONENTS_SOURCES}
    ${CORE_SOURCES}
    ${HEADERS}
)

target_sources(${PROJECT_NAME} PRIVATE ${ALL_SOURCES})

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