add_executable(T_sol2_beep main.cpp)
target_link_libraries(T_sol2_beep lua sol2)

add_test(NAME sol2_beep COMMAND T_sol2_beep)
