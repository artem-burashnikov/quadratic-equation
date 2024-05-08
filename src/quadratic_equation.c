#include "quadratic_equation.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

static size_t get_extra_size(const enum roots_count count) {
    return (count == ROOTS_INF) ? 0 : count;
}

static struct quadratic_equation *init_equation(const float a, const float b, const float c, const enum roots_count count) {
    size_t extra_size = get_extra_size(count);

    struct quadratic_equation *equation = malloc(sizeof(*equation) + extra_size * sizeof(a));
    
    if (!equation) {
        return NULL;
    }

    equation->a = a;
    equation->b = b;
    equation->c = c;

    equation->roots_count = count;

    return equation;
}

void free_equation(struct quadratic_equation *equation) {
    free(equation);
}

struct quadratic_equation *solve_equation(const float a, const float b, const float c) {
    struct quadratic_equation *equation;
    float discr, sqrt_discr;
    
    if (a == 0) {
        if (b == 0) {
            equation = init_equation(a, b, c, ROOTS_INF);
        }
        else {
            equation = init_equation(a, b, c, ROOTS_ONE);

            if (!equation) {
                return NULL;
            }

            equation->roots[0] = -c / b;
        }
    }
    else {
        float discr = b * b - 4 * a * c;

        if (discr < 0) {
            equation = init_equation(a, b, c, ROOTS_ZERO);
        }
        else if (discr == 0) {
            equation = init_equation(a, b, c, ROOTS_ONE);

            if (!equation) {
                return NULL;
            }

            equation->roots[0] = - b / (2 * a);
        }
        else {
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
