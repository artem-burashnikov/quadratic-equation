# Add the source files for the tests executable
add_executable(quadratic_equation_tests main.c)

# Link the shared library to the tests executable
target_link_libraries(quadratic_equation_tests quadratic_equation)

# Add compiler flags
target_compile_options(quadratic_equation_tests PRIVATE -Wall -g)
