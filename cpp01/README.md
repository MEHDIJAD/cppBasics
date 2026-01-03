# C++ Module 01: Memory, References & Switch

## Memory Management
- **Stack vs Heap**:
    - **Stack**: Fast, automatic cleanup. (e.g., `Zombie z;`)
    - **Heap**: Manual control, survives function scope. (e.g., `Zombie* z = new Zombie();`)
- **New/Delete**:
    - `new` allocates memory + calls Constructor.
    - `delete` deallocates memory + calls Destructor.
    - **Array Rule**: If you use `new []`, you MUST use `delete []`.

## Pointers vs References
| Feature | Pointer (`*`) | Reference (`&`) |
| :--- | :--- | :--- |
| Nullable? | Yes (`nullptr`) | No (Must be initialized) |
| Reassignable? | Yes | No (Bound forever) |
| Syntax | `->` to access | `.` to access (looks like object) |

## Switch Statement
- Used in `Harl` to avoid massive `if-else if` chains.
- Efficient jump table for integral types (int, char, enum).

## Project Notes: CPP01

### Ex00: Zombie
- **Objective**: Differentiate between stack and heap allocation.
- **My Code**:
    - `randomChump()`: Creates Zombie on Stack (dies when function ends).
    - `newZombie()`: Creates Zombie on Heap (returned to caller, caller must `delete`).

### Ex04: Sed is for Losers
- **Goal**: Recreate `sed` (replace string in file) using C++.
- **Key method**: `std::string::find()` and `std::string::substr()` or `erase()`/`insert()`.
- **Stream usage**: Read file into `std::stringstream` or line-by-line.

### Ex05: Harl
- **Pointer to Member Functions**:
    - Instead of a long `if/else`, I used an array of function pointers.
    - Syntax: `void (Harl::*ptr)(void) = &Harl::debug;`
    - Calling: `(this->*ptr)();`
