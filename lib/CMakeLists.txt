set(BUILD_SHARED_LIBS OFF)
set(BUILD_TESTING OFF)

#--------------------------------
# LUA
# Scripting language
#--------------------------------
if(NOT TARGET lua)
    add_subdirectory(lua)
endif()

#--------------------------------
# sol2
# Extended C++ support of LUA
#--------------------------------
if(NOT TARGET sol2)
    add_subdirectory(sol2)
endif()
