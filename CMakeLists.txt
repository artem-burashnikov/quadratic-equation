cmake_minimum_required(VERSION 3.10)
project(quadratic-equation)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME tests COMMAND quadratic_equation_tests)

# Add Clang formatting
file(GLOB_RECURSE ALL_SOURCE_FILES *.c *.h)
add_custom_target(format COMMAND clang-format -i ${ALL_SOURCE_FILES})

# Add Valgrind memory check
add_custom_target(memcheck
COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./quadratic_equation_tests DEPENDS quadratic_equation_tests)

# Add make check custom command
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS quadratic_equation_tests)
