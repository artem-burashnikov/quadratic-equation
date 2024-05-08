# quadratic-equation

[![Build status][status-shield]][status-url]
[![MIT License][license-shield]][license-url]

## Overview

The repository provides a C library that calculates roots of a guadratic equation.

## Getting Started

### Prerequisites

- CMake (version 3.10 or higher)
- gcc

### Building

Open the terminal and follow these steps:

1. Clone the repository:

    ```sh
    git clone git@github.com:artem-burashnikov/quadratic-equation.git
    ```

2. Navigate to the project root:

    ```sh
    cd quadratic-equation
    ```

3. Build a static library:

    ```sh
    mkdir build &&
    cd build &&
    cmake .. &&
    make
    ```

5. Now you can include a `quadratic_equation.h` header file in your source files and link a static library `libquadratic_equation.a` during a compilation.

## Usage
Below is an example how you can utilize this library.

### `Solve a quadratic equation`
```c
#include "quadratic_equation.h"
/* Solve a quadratic equation given real-valued coefficients a, b, c. */
struct quadratic_equation* equation = solve_equation(0.16, -0.53, -0.2);

/* Print initial coefficients */
printf("a: %.2f\n", a);
printf("b: %.2f\n", b);
printf("c: %.2f\n", c);

/* Print roots if any. */
for (size_t i = 0; (equation->roots_count != ROOTS_INF) && (i < equation->roots_count); i++) {
    printf("root-%zu: %.2f\n", i, equation->roots[i]);
}

/* Clean up. */
free(equation);
```

`roots_count` &mdash; is delcared in a header and it is the enumerator type that specifies the number of roots.

```c
enum roots_count {
    ROOTS_INF = -1,
    ROOTS_ZERO = 0,
    ROOTS_ONE = 1,
    ROOTS_TWO = 2
};
```

## Licenses

The project is licensed under an [MIT License][license-url].

<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/artem-burashnikov/quadratic-equation?style=for-the-badge&color=blue
[license-url]: LICENSE
[status-shield]: https://img.shields.io/github/actions/workflow/status/artem-burashnikov/quadratic-equation/.github/workflows/ci.yml?branch=main&event=push&style=for-the-badge
[status-url]: https://github.com/artem-burashnikov/quadratic-equation/blob/main/.github/workflows/ci.yml
