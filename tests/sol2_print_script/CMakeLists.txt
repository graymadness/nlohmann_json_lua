add_executable(T_sol2_print_script main.cpp)
target_link_libraries(T_sol2_print_script lua sol2)
configure_file(script.lua script.lua COPYONLY)

add_test(NAME sol2_print_script COMMAND T_sol2_print_script)
