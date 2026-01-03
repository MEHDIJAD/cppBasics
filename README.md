# C++ Basics: Modules 00-04

This project covers the fundamental concepts of C++ programming, from basic syntax to advanced topics like polymorphism and inheritance. Each module is designed to build upon the previous one, providing a solid foundation for object-oriented programming in C++.

## Module 00: Basics & OOP Introduction

### Core Concepts
- **Namespaces**: Used to prevent naming conflicts (e.g., `std::cout`).
- **Classes vs Structs**: `class` members are private by default; `struct` members are public.
- **Input/Output Streams**: `std::cin`, `std::cout`, `std::getline`.
- **Const Correctness**: Using the `const` keyword to prevent modification of class instances.

### Project: PhoneBook
- A contact management system using a static array of 8 contacts.
- Implements a circular buffer to manage the contact list.
- Demonstrates basic class composition.

## Module 01: Memory, References & Switch

### Memory Management
- **Stack vs Heap**: Understanding the difference between automatic and manual memory management.
- **`new` and `delete`**: Allocating and deallocating memory on the heap.

### Pointers vs References
- A comparison of pointers and references, their syntax, and use cases.

### Project: Harl & Zombie
- **Zombie**: Differentiating between stack and heap allocation.
- **Harl**: Using pointers to member functions to avoid long `if-else` chains.

## Module 02: Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Class Form

### Orthodox Canonical Form (OCF)
- The four essential member functions for any class that manages resources:
    1. Default Constructor
    2. Copy Constructor
    3. Copy Assignment Operator
    4. Destructor

### Project: Fixed Point Numbers
- Implementing a fixed-point number class to avoid floating-point precision issues.
- Overloading arithmetic and comparison operators.
- Implementing pre- and post-increment operators.

## Module 03: Inheritance

### Inheritance Types
- **Public, Protected, and Private Inheritance**: Understanding the different access specifiers for base classes.
- **Constructor and Destructor Chaining**: The order in which constructors and destructors are called in an inheritance hierarchy.

### The Diamond Problem
- Understanding and solving the diamond problem using virtual inheritance.

### Project: ClapTrap, ScavTrap, FragTrap, and DiamondTrap
- A series of classes that demonstrate single and multiple inheritance.
- **ClapTrap**: The base class with basic game logic.
- **ScavTrap & FragTrap**: Derived classes that extend the functionality of `ClapTrap`.
- **DiamondTrap**: A class that inherits from both `ScavTrap` and `FragTrap`, demonstrating the diamond problem and its solution.

## Module 04: Subtype Polymorphism

### Virtual Functions
- **Static vs Dynamic Binding**: Understanding the difference between compile-time and runtime polymorphism.
- **The `virtual` keyword**: Using `virtual` to achieve dynamic binding.

### Abstract Classes & Interfaces
- **Pure Virtual Functions**: Creating abstract classes and interfaces.

### Deep Copy
- The importance of deep copying when a class contains pointers to dynamically allocated memory.

### Project: Animal, Brain, and Materia
- **Animal & Brain**: Demonstrating polymorphism with a base `Animal` class and derived `Dog` and `Cat` classes. The `Brain` class is used to illustrate the need for deep copying.
- **Materia**: Implementing an interface (`AMateria`) and a factory (`MateriaSource`) to create different types of "Materia".
