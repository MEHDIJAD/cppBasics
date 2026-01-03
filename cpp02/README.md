# C++ Module 02: Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Class Form

## Orthodox Canonical Form (OCF)

Any class managing resources (and generally all classes in CPP02-09) must implement:
1.  **Default Constructor**: `Class();` - Initializes object to empty state.
2.  **Copy Constructor**: `Class(const Class &copy);` - Creates a *new* object as a clone of an existing one.
3.  **Copy Assignment Operator**: `Class &operator=(const Class &other);` - Updates an *existing* object to match another.
4.  **Destructor**: `~Class();` - Cleans up resources.

### Copy Constructor vs Assignment
- **Copy Constructor**: `Human h2 = h1;` or `Human h2(h1);`
    - *Creating* a new twin.
- **Assignment**: `h2 = h1;` (where h2 already exists).
    - *Overwriting* an existing identity.
    - **Self-assignment check**: Always check `if (this != &other)` to avoid deleting your own data before copying!

## Project: Fixed Point Numbers

### Theory
- **Floating Point Problem**: Floats (IEEE 754) lose precision (e.g., `0.1 + 0.2 != 0.3`).
- **Fixed Point Solution**: Store the number as an integer (`raw bits`) and implicitly assume a decimal point at a fixed position (`fractional bits`).
- **Formula**:
    - `Float -> Fixed`: `round(float * (1 << fractional_bits))`
    - `Fixed -> Float`: `(float)raw / (1 << fractional_bits)`

### My Code (`Fixed.hpp`)
- **OCF Compliant**: Implemented all 4 forms.
- **Operator Overloading**:
    - Comparison: `>`, `<`, `==`, etc.
    - Arithmetic: `+`, `-`, `*`, `/`.
    - **Increment**:
        - Pre-increment (`++i`): Returns reference to *modified* object.
        - Post-increment (`i++`): Returns *copy* of old object, then increments.
- **Static Members**: `min` and `max` helper functions.
