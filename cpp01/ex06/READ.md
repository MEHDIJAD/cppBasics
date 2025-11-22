# Understanding the `switch` Statement in C++

The `switch` statement in C++ is a control flow statement that allows you to execute different blocks of code based on the value of a single variable or expression. It's an alternative to a long chain of `if-else if` statements when you're checking a variable against multiple constant values.

## Purpose

To perform different actions based on different conditions, specifically when those conditions are based on the exact value of one variable.

## Syntax

```cpp
switch (expression) {
    case constant_value_1:
        // code to execute if expression == constant_value_1
        break; // Important: exits the switch block
    case constant_value_2:
        // code to execute if expression == constant_value_2
        break;
    // ... more case labels
    default:
        // code to execute if expression doesn't match any case
        break; // Optional, but good practice if default is last
}
```

## Key Components

1.  **`expression`**:
    *   The `expression` inside `switch()` must evaluate to an integral type (like `int`, `char`, `short`, `long`, `enum`).
    *   It cannot be a `std::string` or a floating-point type directly.

2.  **`case` labels**:
    *   Each `case` label must be followed by a unique constant integral value.
    *   The code block associated with a `case` label is executed if the `expression` matches that `constant_value`.

3.  **`break` keyword**:
    *   This is crucial. After the code for a `case` is executed, `break` immediately terminates the `switch` statement, and execution continues after the `switch` block.
    *   **Without `break` (Fall-through)**: If you omit `break`, execution will "fall through" to the next `case` label, executing its code as well, regardless of whether its `constant_value` matches the `expression`. This is usually an error, but it can be intentionally used for specific logic (as required in `ex06`).

4.  **`default` keyword**:
    *   The `default` case is optional. If present, its code block is executed when the `expression` does not match any of the `case` labels. It acts like the final `else` in an `if-else if` chain.

## Example

```cpp
#include <iostream>

int main() {
    int day = 3;

    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        default:
            std::cout << "Weekend or invalid day" << std::endl;
            break;
    }
    return 0;
}
// Output: Wednesday
```

## Relevance to `ex06`

For `ex06`, you'll need to map the input `std::string` (e.g., "WARNING") to an integral value (e.g., 0, 1, 2, 3) that can be used in the `switch` statement. Then, you'll intentionally use **fall-through** to print messages from the specified level and all subsequent levels. For example:

```cpp
// Assuming 'level_int' is 2 for WARNING
switch (level_int) {
    case 0: // DEBUG
        harl.debug();
        // NO BREAK HERE - fall through to INFO
    case 1: // INFO
        harl.info();
        // NO BREAK HERE - fall through to WARNING
    case 2: // WARNING
        harl.warning();
        // NO BREAK HERE - fall through to ERROR
    case 3: // ERROR
        harl.error();
        break; // Break here to stop after ERROR
    default:
        // Handle invalid input
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
}
```
