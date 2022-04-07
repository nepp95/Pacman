cmake_minimum_required(VERSION 3.12)

project(Pacman VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
list(APPEND SDL2_PATH "C:/Users/Niels/source/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} src)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_compile_definitions(PUBLIC DEBUG)

add_executable(Pacman ${SOURCES})
target_link_libraries(Pacman ${SDL2_LIBRARIES})