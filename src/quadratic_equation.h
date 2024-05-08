#ifndef __QUADRATIC_EQUATION_H__
#define __QUADRATIC_EQUATION_H__

/* Possible number of roots of a quadratic equation. */
enum roots_count {
    ROOTS_INF  = -1,
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2
};

struct quadratic_equation {
    /* Real coefficients of the quadratic polynomial. */
    float a;
    float b;
    float c;
    /* Length of the roots array. */
    enum roots_count roots_count;
    /* Flexible array member containing roots values. */
    float roots[];
};

/* Free a memory allocated for quadratic equation structure. */
void free_equation(struct quadratic_equation *equation);

/* Solve ax^2 + bx + c = 0 given coefficients a, b, c. */
struct quadratic_equation *solve_equation(const float a, const float, const float c);

#endif /* __QUADRATIC_EQUATION_H__ */
