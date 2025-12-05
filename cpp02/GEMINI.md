# Project Overview

This project appears to be a series of C++ exercises focused on creating a `Fixed` class for fixed-point number representation. The project is divided into directories, `ex00` and `ex01`, which seem to represent iterative steps in the development of the class.

**Key Technologies:**
*   C++

**Architecture:**
*   The core of the project is the `Fixed` class, defined in `Fixed.hpp` and implemented in `Fixed.cpp`.
*   Each exercise directory (`ex00`, `ex01`) contains a `main.cpp` file to test the functionality of the `Fixed` class at that stage.
*   A `Makefile` is provided in each directory to compile the code.

# Building and Running

To build and run the exercises, navigate to the respective directory (`ex00` or `ex01`) and use the following commands:

*   **Build:** `make`
*   **Run:** `./Fixed`
*   **Clean:** `make clean`
*   **Full Rebuild:** `make re`

# Development Conventions

*   The code follows the C++98 standard, as specified by the `-std=c++98` flag in the `Makefile`.
*   Header files are protected by include guards (`#ifndef _FIXED_HPP_`).
*   The code uses the `-Wall -Wextra -Werror` compiler flags, indicating a high standard of code quality with no compiler warnings allowed.
