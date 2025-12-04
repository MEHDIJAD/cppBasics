# Project Overview

This project is a C++ exercise that implements a fixed-point number class called `Fixed`. The purpose is to understand and practice class creation, copy constructors, assignment operators, and basic C++ compilation using a `Makefile`.

**Key Technologies:**
*   C++

**Architecture:**
*   The `Fixed` class represents a fixed-point number.
*   It stores the value in an integer (`fixedPoint`).
*   A static constant `FRACTIONAL_BITS` defines the number of fractional bits.
*   The project is built using a `Makefile`.

# Building and Running

**Build:**
```bash
make
```

**Run:**
```bash
./Fixed
```

**Clean:**
```bash
make clean
```

**Full Clean:**
```bash
make fclean
```

**Rebuild:**
```bash
make re
```

# Development Conventions

*   The code follows the C++98 standard.
*   Compiler flags `-Wall -Wextra -Werror` are used to enforce strict compilation.
*   The class implementation is separated into `.hpp` (header) and `.cpp` (source) files.
*   The `main.cpp` file is used to test the `Fixed` class.
