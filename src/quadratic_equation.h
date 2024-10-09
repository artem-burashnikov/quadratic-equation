#ifndef __QUADRATIC_EQUATION_H__
#define __QUADRATIC_EQUATION_H__

/* Possible number of roots of a quadratic equation. */
enum roots_count {
    ROOTS_INF = 0,
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2
};

struct quadratic_equation {
    /* Real coefficients of the quadratic polynomial. */
    double a;
    double b;
    double c;
    /* Length of the roots array. */
    enum roots_count roots_count;
    /* Flexible array member containing roots values. */
    double roots[];
};

/* Solve ax^2 + bx + c = 0 given coefficients a, b, c. */
struct quadratic_equation* solve_equation(const double a,
                                          const double b,
                                          const double c);

#endif /* __QUADRATIC_EQUATION_H__ */
