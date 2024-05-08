# Add static library sources.
add_library(quadratic_equation STATIC quadratic_equation.c)

target_include_directories(quadratic_equation PUBLIC ${CMAKE_SOURCE_DIR}/src)
