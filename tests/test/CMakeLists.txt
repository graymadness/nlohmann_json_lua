add_executable(T_Test main.cpp)
target_link_libraries(T_Test nlohmann_json_lua)

add_test(NAME Test COMMAND T_Test)
