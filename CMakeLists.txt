cmake_minimum_required(VERSION 3.16)

# Set project settings
project(Pacman VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

####################
## INCLUDE        ##
####################

# Locate packages
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)

# Include dirs
include_directories(${SDL2_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} "src" "vendor/entt/include")


####################
## END INCLUDE    ##
####################

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Define DEBUG
add_compile_definitions(DEBUG)

# Create executable
add_executable(Pacman ${SOURCES})
target_link_libraries(Pacman ${SDL2_LIBRARIES})
target_precompile_headers(Pacman PRIVATE "src/pch.h")