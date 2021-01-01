#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

int main()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);

    lua.script("print('Hello, World!')");
}
