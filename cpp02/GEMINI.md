# C++ Project: Fixed-Point Number

## Project Overview

This project consists of a series of exercises to create a fixed-point number class in C++. The project is divided into directories, each representing a step in the development of the `Fixed` class.

**Main Technologies:** C++

**Architecture:** The project follows an object-oriented approach, with a `Fixed` class that encapsulates the fixed-point number representation and operations. The exercises are structured to incrementally add functionality to the `Fixed` class.

## Building and Running

The project uses `make` to build the executables. Each exercise directory (`ex00`, `ex01`, etc.) contains a `Makefile`.

To build and run an exercise, navigate to its directory and use the following commands:

```bash
# Go to the exercise directory
cd ex00

# Build the project
make

# Run the executable
./Fixed

# Clean the build files
make clean

# Clean all files including the executable
make fclean

# Rebuild the project
make re
```

## Development Conventions

*   **Coding Style:** The code follows the C++98 standard. The class definition is in a `.hpp` file and the implementation in a `.cpp` file.
*   **Orthodox Canonical Form:** The `Fixed` class in `ex00` implements the Orthodox Canonical Form, which includes a default constructor, a copy constructor, an assignment operator, and a destructor.
*   **Testing:** Each exercise has a `main.cpp` file that serves as a test driver for the `Fixed` class, demonstrating its features.

## Directory Overview

*   `en.subject.pdf`: The project subject description (in English).
*   `ex00/`: The first exercise, which introduces the `Fixed` class in its Orthodox Canonical Form.
*   `ex01/`: The second exercise, which adds constructors for `int` and `float`, and conversion functions `toFloat()` and `toInt()`.
