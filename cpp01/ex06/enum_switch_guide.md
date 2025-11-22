# Guide: Using `enum` with `switch` for ex06

You are correct that using an `enum` is the right way to solve `ex06`. A `switch` statement only works with integral types (like `int` or an `enum`), so you cannot use a `std::string` directly.

The solution is a two-step process:

1.  **Map the input `std::string` to an `enum` value.**
2.  **Use that `enum` value in your `switch` statement.**

Here is a complete guide on how to structure this logic in your `main.cpp`.

---

### Step 1: Create the String-to-Enum Mapping

First, define an `enum` for your levels. It's good practice to include a default state (like `NONE` or `INVALID`) for inputs that don't match. Then, create a function that performs the conversion from a string to your new `enum` type.

```cpp
#include "Harl.hpp"
#include <iostream>

// Define an enum for the levels.
enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE // For handling invalid input
};

// This function takes a string and returns the corresponding enum value.
Level getLevelFromString(std::string levelStr) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == levelStr) {
            // We found a match. Cast the integer index 'i' to our enum type
            // and return it.
            return static_cast<Level>(i);
        }
    }
    // If the loop finishes without finding a match, return NONE.
    return NONE;
}
```

---

### Step 2: Use the Enum in `main` with a `switch`

Now, your `main` function can use this mapping to get an `enum` value and feed it into the `switch` statement. The `switch` will use **fall-through** (omitting the `break` statement) to execute all cases from the matched level downwards.

```cpp
int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return 1;
    }

    // 1. Get the enum value from the input string.
    Level filterLevel = getLevelFromString(av[1]);

    harl myHarl;

    // 2. Switch on the enum value.
    switch (filterLevel)
    {
        case DEBUG:
            myHarl.debug();
            // Fall-through to INFO
        case INFO:
            myHarl.info();
            // Fall-through to WARNING
        case WARNING:
            myHarl.warning();
            // Fall-through to ERROR
        case ERROR:
            myHarl.error();
            break; // Stop after the last level
        default: // This case will catch 'NONE' for any invalid input
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }

    return 0;
}
```

This structure perfectly matches the requirements of the exercise. It correctly uses an `enum` to control a `switch` statement and implements the required fall-through logic to filter Harl's messages.