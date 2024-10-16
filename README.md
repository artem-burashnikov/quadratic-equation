# quadratic-equation

[![Build status][status-shield]][status-url]
[![MIT License][license-shield]][license-url]

## Overview

The repository provides a C library that calculates roots of a guadratic equation.

## Getting Started

### Prerequisites

- GNU Make (version 4.4.1 or higher)
- gcc

### Building

Open the terminal and follow these steps:

1. Clone the repository:

    ```sh
    git clone git@github.com:artem-burashnikov/quadratic-equation.git
    ```

2. Build a testing executable:

    ```sh
    cd quadratic-equation && make
    ```

3. Now you can link `quadratic_equation.o` during a compilation.

## Usage
Below is an example how you can utilize this library.

### `Solve a quadratic equation`
```c
#include "quadratic_equation.h"
/* Solve a quadratic equation given real-valued coefficients a, b, c. */
struct quadratic_equation* equation = solve_equation(0.16, -0.53, -0.2);

/* Print initial coefficients */
printf("a: %.2f\n", equation->a);
printf("b: %.2f\n", equation->b);
printf("c: %.2f\n", equation->c);

/* Print roots if any. */
for (size_t i = 0; i < equation->roots_count; i++) {
    printf("root-%zu: %.2f\n", i, equation->roots[i]);
}

/* Clean up. */
free(equation);
```

Defined abstractions are exposed in a header.

## Licenses

The project is licensed under an [MIT License][license-url].

<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/artem-burashnikov/quadratic-equation?style=for-the-badge&color=blue
[license-url]: LICENSE
[status-shield]: https://img.shields.io/github/actions/workflow/status/artem-burashnikov/quadratic-equation/.github/workflows/ci.yml?branch=main&event=push&style=for-the-badge
[status-url]: https://github.com/artem-burashnikov/quadratic-equation/blob/main/.github/workflows/ci.yml
