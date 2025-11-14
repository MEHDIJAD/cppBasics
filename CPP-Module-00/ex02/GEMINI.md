# Project Overview

This project is a C++ exercise from a C++ module. The main goal is to recreate the `Account.cpp` file based on the provided header file (`Account.hpp`), a testing file (`tests.cpp`), and a log file (`19920104_091532.log`) that shows the expected output.

The project revolves around a simple `Account` class that simulates basic banking operations like deposits and withdrawals.

## Building and Running

To build and run this project, you will need a C++ compiler (like g++). The `subject.txt` file mentions a `Makefile`, which is not present in the directory. A possible compile command could be:

```bash
g++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o tests
```

To run the compiled program:

```bash
./tests
```

The output should match the provided log file `19920104_091532.log` (timestamps will differ).

## Development Conventions

*   The code follows the C++98 standard.
*   The header file `Account.hpp` is well-documented with doxygen-style comments.
*   The code uses a `_` prefix for private member variables.
*   The project uses a `Makefile` for building (though it is not provided).
