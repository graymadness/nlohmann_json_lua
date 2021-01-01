add_executable(T_sol2_print main.cpp)
target_link_libraries(T_sol2_print lua sol2)

add_test(NAME sol2_print COMMAND T_sol2_print)
