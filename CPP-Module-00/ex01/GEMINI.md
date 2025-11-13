# GEMINI.md

## Project Overview

This project is a simple command-line phonebook application written in C++. It allows users to manage a list of contacts. The application supports adding new contacts, searching for existing contacts, and exiting the program. The phonebook has a fixed capacity of 8 contacts. When a user adds a 9th contact, the oldest contact is overwritten.

The main components are:
- **`PhoneBook` class:** Manages the contacts, including adding and displaying them.
- **`Contact` class:** Represents a single contact with fields for first name, last name, nickname, phone number, and a "darkest secret".
- **`main.cpp`:** Contains the main loop that handles user input and calls the appropriate methods.

## Building and Running

The project uses a `Makefile` for building the executable.

### Build Commands

- **`make` or `make all`**: Compiles the source files and creates the `PhoneBook` executable.
- **`make clean`**: Removes the intermediate object files (`.o`).
- **`make fclean`**: Removes all build artifacts, including the `PhoneBook` executable and object files.
- **`make re`**: Performs a full rebuild (`fclean` followed by `all`).
- **`make run`**: Compiles the project and removes the object files.

### Running the Application

To run the phonebook application, execute the following command in your terminal:

```bash
./PhoneBook
```

The application will then prompt you for commands.

## Development Conventions

- **Language:** The project is written in C++98.
- **File Structure:** Header files (`.hpp`) are used for class declarations, and source files (`.cpp`) are used for implementations.
- **Class Design:** The code follows object-oriented principles with `Contact` and `PhoneBook` classes. Data members are private, and access is provided through public member functions (getters and setters).
- **Input Handling:** The application reads commands (`ADD`, `SEARCH`, `EXIT`) from standard input. It includes basic input validation.
- **Error Handling:** The code includes some basic error handling, for example, for invalid input formats.
- **Style:** The code uses a consistent style, including comments for constructors, destructors, and other class members.
