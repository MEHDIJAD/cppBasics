# C++ Module 00: Basics & OOP Introduction

## Core Concepts
- **Namespaces**: Used to prevent naming conflicts (e.g., `std::cout`). We must avoid `using namespace std;` to understand where functions come from.
- **Classes vs Structs**: In C++, `class` members are private by default; `struct` members are public.
- **Input/Output Streams**:
    - `std::cin` vs `std::getline`:
        - `std::cin >> var` stops at whitespace (bad for names like "Jean Pierre").
        - `std::getline(std::cin, var)` reads the whole line.
        - **Tip**: Always handle the buffer! If you mix `cin >>` and `getline`, you might leave a newline `\n` in the buffer that skips the next input.
- **Const Correctness**:
    - `int getVal() const;` -> This function promises not to modify the class instance.

## Project: PhoneBook (My Implementation)

### Overview
A specific implementation of a contact management system using an array of 8 contacts.

### Code Analysis
Based on `PhoneBook.hpp`:
- **Storage**: `Contact _Contacts[8];` (Static array, no dynamic allocation yet).
- **Circular Buffer Logic**: `_nextIndex` tracks the oldest contact to replace when the book is full.
- **Composition**: `PhoneBook` *has-a* `Contact`.

### My Implementation Details
- **Contact Class**:
    - Stores fields: First Name, Last Name, Nickname, Phone Number, Darkest Secret.
    - Used `std::string` for all fields.
- **Main Loop**:
    - Supports commands: `ADD`, `SEARCH`, `EXIT`.
    - `SEARCH` displays a formatted table (width 10, right-aligned) using `std::setw`.
