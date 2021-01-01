cmake_minimum_required (VERSION 3.16)
project (lua C)

if(WIN32)
    add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif()

#--------------------------------
# Library
#--------------------------------

file(GLOB LUA_SOURCE src/*.h src/*.c)
list(REMOVE_ITEM LUA_SOURCE ${PROJECT_SOURCE_DIR}/src/lua.c) # Remove interpreter

add_library (lua STATIC ${LUA_SOURCE})
target_include_directories(lua PUBLIC src/)
