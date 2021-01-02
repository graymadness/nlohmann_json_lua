# nlohmann's JSON from LUA

Allow LUA access to nlohmann's JSON instance

## Libraries

| Name | License | Version |
|------|---------|---------|
| [LUA](https://github.com/lua/lua) | [`MIT`](https://www.lua.org/license.html) | branch: [`master`](https://github.com/lua/lua/tree/master/) |
| [nlohmann JSON](https://nlohmann.github.io/json/) | [`MIT`](https://github.com/nlohmann/json/blob/master/LICENSE.MIT) | branch: [`master`](https://github.com/nlohmann/json/tree/master) |

All libraries are used as `static library` to maximize optimization and limit problems with deployment and versions.

## Testing

Run `ctest` in build directory, must have `BUILD_TESTING=ON` in CMake.

## Example

```lua
local json = JSON.parse('{ "a": 123, "abcd": "text", "b": true}')
print(#json)
print(json)
```
