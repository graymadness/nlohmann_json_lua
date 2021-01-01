add_executable(T_sol2_boop main.cpp)
target_link_libraries(T_sol2_boop lua sol2)

add_test(NAME sol2_boop COMMAND T_sol2_boop)
