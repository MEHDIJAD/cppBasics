# Project Overview

This is a simple C++ project from the `cpp01` module. It introduces the concept of classes and objects in C++ by creating a `Zombie` class. The `main` function demonstrates creating zombies on the stack and heap.

# Building and Running

The project uses a `Makefile` for building.

*   `make`: Compiles the project.
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and the executable.
*   `make re`: Rebuilds the project.
*   `make run`: Compiles and runs the executable.

To run the compiled program:
```bash
cd ex00
./Zombie
```

# Development Conventions

*   The code is written in C++98.
*   The header file `Zombie.hpp` uses `#pragma once` and include guards.
*   The `Zombie` class has a constructor and a destructor.
