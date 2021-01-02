#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <nlohmann/json/lua.hpp>

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    nlohmann::lua::luaopen_array(L);

    int error_code;

    std::cout << std::endl << "1" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "json = JSON.parse('{ \"a\": 123, \"abcd\": \"text\", \"b\": true, \"arr\": [1, 2, 3] }')\n"
                               "print(#json)\n"
                               "print(json)\n"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));

    std::cout << std::endl << "2" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "print(json['a'])\n"
                               "print(json['abcd'])\n"
                               "print(json['b'])\n"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));

    std::cout << std::endl << "3" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "print(json)\n"
                               "print(JSON.type(json))\n"
                               "print('. of ' .. type(json) .. '/' .. JSON.type(json) .. ': ' .. tostring(json))\n"
                               "print('[arr] of ' .. type(json['arr']) .. '/' .. JSON.type(json['arr']) .. ': ' .. tostring(json['arr']))\n"
                               "print('[arr][1] of ' .. type(json['arr'][1]) .. '/' .. JSON.type(json['arr'][1]) .. ': ' .. tostring(json['arr'][1]))\n"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));

    std::cout << std::endl << "4" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "for k,v in pairs(getmetatable(json)) do print(k .. ' ~ ' .. tostring(v)) end"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));

    /*
    std::cout << std::endl << "5" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "for k,v in pairs(json) do print(k .. ' ~ ' .. tostring(v)) end"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));

    std::cout << std::endl << "6" << std::endl << std::endl;

    error_code = luaL_dostring(L,
                               "for k,v in ipairs(json) do print(k .. ' ~ ' .. tostring(v)) end"
                              );
    if(error_code != 0)
        throw std::runtime_error(lua_tostring(L, -1));
    */

    std::cout << std::endl << "Done" << std::endl << std::endl;
}
