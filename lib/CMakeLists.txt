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
# nlohmann JSON
# JSON for Modern C++
#--------------------------------

if(NOT TARGET nlohmann_json)
    set(JSON_BuildTests OFF)
    set(JSON_Install OFF)
    add_subdirectory(nlohmann_json)
endif()
