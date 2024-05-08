#include "quadratic_equation.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#define EXTRA(x) ((x) < 0 ? 0 : (x))

/* Initialize quadratic_equation structure. */
static struct quadratic_equation* init_equation(const double a,
                                                const double b,
                                                const double c,
                                                const enum roots_count count) {
    size_t extra;
    struct quadratic_equation* equation;

    /* Allocate neccesary size for struct
     * considering extra space needed for the number of roots.
     */
    equation = malloc(sizeof(*equation) + EXTRA(count) * sizeof(double));

    if (!equation) {
        return NULL;
    }

    /* Assign values of quadratic coefficients and roots count. */
    equation->a = a;
    equation->b = b;
    equation->c = c;

    equation->roots_count = count;

    return equation;
}

struct quadratic_equation* solve_equation(const double a,
                                          const double b,
                                          const double c) {
    struct quadratic_equation* equation;
    double discr, sqrt_discr;

    /* Depending on which coefficients are zero, there are 4 cases for roots
     * count. */
    if (a == 0) {
        if (b == 0) {
            /* a = 0, b = 0, c is any */
            equation = init_equation(a, b, c, ROOTS_INF);
        } else {
            /* a = 0, b <> 0, c is any */
            equation = init_equation(a, b, c, ROOTS_ONE);

            if (!equation) {
                return NULL;
            }

            equation->roots[0] = -c / b;
        }
    } else {
        /* a <> 0 means we have to solve a quadratic equation. */
        discr = b * b - 4 * a * c;

        if (discr < 0) {
            equation = init_equation(a, b, c, ROOTS_ZERO);
        } else if (discr == 0) {
            equation = init_equation(a, b, c, ROOTS_ONE);

            if (!equation) {
                return NULL;
            }

            equation->roots[0] = -b / (2 * a);
        } else {
            equation = init_equation(a, b, c, ROOTS_TWO);

            if (!equation) {
                return NULL;
            }

            sqrt_discr = sqrt(discr);

            equation->roots[0] = (-b + sqrt_discr) / (2 * a);
            equation->roots[1] = (-b - sqrt_discr) / (2 * a);
        }
    }

    return equation;
}
