#include "quadratic_equation.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#define EXTRA(x) ((x) < 0 ? 0 : (x))

static struct quadratic_equation* init_equation(const float a,
                                                const float b,
                                                const float c,
                                                const enum roots_count count) {
    size_t extra;
    struct quadratic_equation* equation;

    equation = malloc(sizeof(*equation) + EXTRA(count) * sizeof(float));

    if (!equation) {
        return NULL;
    }

    equation->a = a;
    equation->b = b;
    equation->c = c;

    equation->roots_count = count;

    return equation;
}

struct quadratic_equation* solve_equation(const float a,
                                          const float b,
                                          const float c) {
    struct quadratic_equation* equation;
    float discr, sqrt_discr;

    if (a == 0) {
        if (b == 0) {
            equation = init_equation(a, b, c, ROOTS_INF);
        } else {
            equation = init_equation(a, b, c, ROOTS_ONE);

            if (!equation) {
                return NULL;
            }

            equation->roots[0] = -c / b;
        }
    } else {
        float discr = b * b - 4 * a * c;

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

            sqrt_discr = sqrtf(discr);

            equation->roots[0] = (-b + sqrt_discr) / (2 * a);
            equation->roots[1] = (-b - sqrt_discr) / (2 * a);
        }
    }

    return equation;
}
