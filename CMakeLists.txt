cmake_minimum_required(VERSION 3.16)
project(nlohmann_json_lua C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

cmake_policy(SET CMP0077 NEW) # set() overrides option()

#--------------------------------
# Debug Options
#--------------------------------

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>") # Define DEBUG in Debug builds

#--------------------------------
# Compiler configuration
#--------------------------------

if(MINGW)
    message(NOTICE "MinGW detected, setting compilation to Windows")
    set(WIN32 ON)
endif()

#--------------------------------
# External libraries
#--------------------------------

add_subdirectory(lib)

#--------------------------------
# Source
#--------------------------------

file(GLOB_RECURSE PROJECT_SOURCE src/*.hpp src/*.cpp src/*.h src/*.c)

add_library(nlohmann_json_lua STATIC ${PROJECT_SOURCE})
target_include_directories(nlohmann_json_lua PUBLIC src/)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(nlohmann_json_lua -static-libgcc -static-libstdc++)
endif()
target_link_libraries(nlohmann_json_lua nlohmann_json lua)

#--------------------------------
# Source
#--------------------------------

if(BUILD_TESTING)
    include(CTest)
    enable_testing()

    add_subdirectory(tests)
endif()
