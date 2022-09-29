add_executable(test_a test_a.cpp)
add_executable(test_b test_b.cpp)
add_executable(test_c test_c.cpp)

target_link_libraries(test_a PRIVATE libparta m Catch2::Catch2)
target_compile_options(test_a PUBLIC -ggdb -fsanitize=address)
target_link_options(test_a PUBLIC -fsanitize=address)

target_link_libraries(test_b PRIVATE libpartb m Catch2::Catch2)
target_compile_options(test_b PUBLIC -ggdb -fsanitize=address)
target_link_options(test_b PUBLIC -fsanitize=address)

target_link_libraries(test_c PRIVATE libpartc m Catch2::Catch2)
target_compile_options(test_c PUBLIC -ggdb -fsanitize=address)
target_link_options(test_c PUBLIC -fsanitize=address)

catch_discover_tests(test_a)
catch_discover_tests(test_b)
catch_discover_tests(test_c)
