cmake_minimum_required(VERSION 3.10)
project(quadratic-equation)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME tests COMMAND quadratic_equation_tests)

# Add Clang formatting
file(GLOB_RECURSE ALL_SOURCE_FILES *.c *.h)
add_custom_target(format COMMAND clang-format -style='{BasedOnStyle: Chromium, IndentWidth: 4}' -i ${ALL_SOURCE_FILES})

# Add Valgrind memory check
add_custom_target(memcheck
COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./tests/quadratic_equation_tests DEPENDS quadratic_equation_tests)

target_include_directories(quadratic_equation_tests PUBLIC tests)

# Add make check custom command
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS quadratic_equation_tests)
