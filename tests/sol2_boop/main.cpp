#include <cassert>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

struct vars
{
    int boop = 0;
};

int main()
{
    sol::state lua;
    lua.new_usertype<vars>("vars", "boop", &vars::boop);
    lua.script("beep = vars.new()\n"
               "beep.boop = 1");
    assert(lua.get<vars>("beep").boop == 1);
}
