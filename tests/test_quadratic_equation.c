#include <math.h>
#include <stdlib.h>
#include "minunit.h"
#include "quadratic_equation.h"

#define VIETE_TEST(x1, x2, a, b, c)                   \
    do {                                              \
        mu_assert_double_eq((x1) + (x2), -(b) / (a)); \
        mu_assert_double_eq((x1) * (x2), (c) / (a));  \
    } while (0)

MU_TEST(all_zero_coefficients) {
    struct quadratic_equation* equation = solve_equation(0, 0, 0);

    mu_check(equation->a == 0);
    mu_check(equation->b == 0);
    mu_check(equation->c == 0);

    mu_check(equation->roots_count == ROOTS_INF);

    free(equation);
}

MU_TEST(non_zero_c) {
    struct quadratic_equation* equation = solve_equation(0, 0, 0.25);

    mu_check(equation->roots_count == ROOTS_INF);

    free(equation);
}

MU_TEST(non_zero_b) {
    struct quadratic_equation* equation = solve_equation(0, -0.3, 0);

    mu_check(equation->roots_count == ROOTS_ONE);
    mu_check(equation->roots[0] == 0.0);

    free(equation);
}

MU_TEST(non_zero_b_c) {
    struct quadratic_equation* equation1 = solve_equation(0, -0.25, 0.25);

    mu_check(equation1->roots_count == ROOTS_ONE);
    mu_check(equation1->roots[0] == 1.0);

    struct quadratic_equation* equation2 = solve_equation(0, 0.3, 0.13);

    mu_check(equation2->roots_count == ROOTS_ONE);
    mu_assert_double_eq(equation2->roots[0], (-0.13 / 0.3));

    free(equation1);
    free(equation2);
}

MU_TEST(non_zero_a) {
    struct quadratic_equation* equation = solve_equation(0.25, 0, 0);

    mu_check(equation->roots_count == ROOTS_ONE);
    mu_check(equation->roots[0] == 0.0);

    free(equation);
}

MU_TEST(non_zero_a_c) {
    struct quadratic_equation* equation = solve_equation(0.25, 0, 1);

    mu_check(equation->roots_count == ROOTS_ZERO);

    free(equation);
}

MU_TEST(non_zero_a_neg_c) {
    struct quadratic_equation* equation = solve_equation(0.25, 0, -1);

    mu_check(equation->roots_count == ROOTS_TWO);
    VIETE_TEST(equation->roots[0], equation->roots[1], 0.25, 0, -1);

    free(equation);
}

MU_TEST(non_zero_a_b) {
    struct quadratic_equation* equation = solve_equation(0.25, 0.31, 0);

    mu_check(equation->roots_count == ROOTS_TWO);
    VIETE_TEST(equation->roots[0], equation->roots[1], 0.25, 0.31, 0);

    free(equation);
}

MU_TEST(non_zero_a_neg_b) {
    struct quadratic_equation* equation = solve_equation(0.256, -0.153, 0);

    mu_check(equation->roots_count == ROOTS_TWO);
    VIETE_TEST(equation->roots[0], equation->roots[1], 0.256, -0.153, 0);

    free(equation);
}

MU_TEST(non_zero_a_b_c) {
    struct quadratic_equation* equation = solve_equation(0.16, -0.53, -0.2);

    mu_check(equation->roots_count == ROOTS_TWO);
    VIETE_TEST(equation->roots[0], equation->roots[1], 0.16, -0.53, -0.2);

    free(equation);
}

MU_TEST_SUITE(infinity_roots) {
    MU_RUN_TEST(all_zero_coefficients);
    MU_RUN_TEST(non_zero_c);
}

MU_TEST_SUITE(linear_equations) {
    MU_RUN_TEST(non_zero_b);
    MU_RUN_TEST(non_zero_b_c);
}

MU_TEST_SUITE(quadratic_equations) {
    MU_RUN_TEST(non_zero_a);
    MU_RUN_TEST(non_zero_a_c);
    MU_RUN_TEST(non_zero_a_neg_c);
    MU_RUN_TEST(non_zero_a_b);
    MU_RUN_TEST(non_zero_a_neg_b);
    MU_RUN_TEST(non_zero_a_b_c);
}

int main(int argc, char* argv[]) {
    MU_RUN_SUITE(infinity_roots);
    MU_RUN_SUITE(linear_equations);
    MU_RUN_SUITE(quadratic_equations);
    MU_REPORT();
    return MU_EXIT_CODE;
}
