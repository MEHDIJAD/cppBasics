# Notes for ex01

## Understanding `const` Parameters and Bit Shifting

You asked how you can "change" a `const int` parameter when performing a bit shift. This is a common point of confusion, so let's clarify:

The `const` keyword in a function parameter like `const int decimal` means that **within the scope of that function (e.g., the constructor), the variable `decimal` itself cannot be modified.** It makes the parameter read-only.

When you perform an operation like:

```cpp
fixedPoint = decimal << FRACTIONAL_BITS;
```

You are **not modifying the original `decimal` variable**. Instead, you are doing the following:

1.  **Reading the value:** The value of `decimal` is read from memory.
2.  **Performing an operation:** The bit-shift operation (`<< FRACTIONAL_BITS`) is performed on this *read value*. This operation produces a **new, temporary result**.
3.  **Assignment:** This new, temporary result is then assigned to the `fixedPoint` member variable.

The original `decimal` variable remains unchanged, thus respecting the `const` contract. The `const` ensures that the caller's original variable is safe from accidental modification by your function.

## How to Shift for Fixed-Point Conversion

In fixed-point arithmetic, a number is represented by an integer where a certain number of bits are implicitly considered to be after the "decimal point" (or, more accurately, the binary point).

For `ex01`, `FRACTIONAL_BITS` is defined as 8. This means that the last 8 bits of your `fixedPoint` integer represent the fractional part, and the remaining bits represent the integer part.

To convert an integer `n` into this fixed-point format:

*   **Integer Part:** The integer part of `n` needs to be moved to the left by `FRACTIONAL_BITS` positions to make space for the fractional part.
*   **Fractional Part:** Since an integer `n` has no fractional part, the fractional bits will all be zero after the shift.

The operation to achieve this is a **left bit shift**:

```cpp
fixedPoint = n << FRACTIONAL_BITS;
```

**Example:**
Let `FRACTIONAL_BITS = 8`.
If `n = 1` (binary `...00000001`)
`n << 8` would result in `...000100000000` (which is 256 in decimal).
In fixed-point representation, this `256` would be interpreted as `1.0`.

If `n = 5` (binary `...00000101`)
`n << 8` would result in `...010100000000` (which is 1280 in decimal).
In fixed-point representation, this `1280` would be interpreted as `5.0`.

This effectively scales the integer `n` by `2^FRACTIONAL_BITS`, preparing it for fixed-point operations.

---

### How Bit Shifts Work (General and in `Fixed` Class)

Let's break down how bit shifts work, especially in the context of integers and powers of two.

#### What is a Bit Shift?

A bit shift is an operation that moves the bits of a binary number to the left or right.

*   **Left Shift (`<<`)**: Moves all bits to the left by a specified number of positions. New positions on the right are filled with zeros.
*   **Right Shift (`>>`)**: Moves all bits to the right by a specified number of positions. New positions on the left are filled with zeros (for unsigned numbers) or with the sign bit (for signed numbers, to preserve the sign).

#### Bit Shifts and Powers of Two

The magic of bit shifts is their direct relationship with powers of two:

1.  **Left Shift (`X << N`) is equivalent to multiplying `X` by `2^N`**
    *   Each left shift by one position effectively doubles the number.
    *   `X << 1` is `X * 2^1` (X multiplied by 2)
    *   `X << 2` is `X * 2^2` (X multiplied by 4)
    *   `X << N` is `X * 2^N`

2.  **Right Shift (`X >> N`) is equivalent to dividing `X` by `2^N`**
    *   Each right shift by one position effectively halves the number (integer division).
    *   `X >> 1` is `X / 2^1` (X divided by 2)
    *   `X >> 2` is `X / 2^2` (X divided by 4)
    *   `X >> N` is `X / 2^N`

#### Examples:

Let's take the integer `5`. In an 8-bit binary representation, `5` is `00000101`.

*   **Left Shift Example (`5 << 1`)**:
    `00000101` (5)
    `<< 1` (shift left by 1)
    `00001010` (10)
    Result: `10`. This is `5 * 2^1`.

*   **Left Shift Example (`5 << 2`)**:
    `00000101` (5)
    `<< 2` (shift left by 2)
    `00010100` (20)
    Result: `20`. This is `5 * 2^2`.

*   **Right Shift Example (`5 >> 1`)**:
    `00000101` (5)
    `>> 1` (shift right by 1)
    `00000010` (2)
    Result: `2`. This is `5 / 2^1` (integer division).

#### How it applies to your `Fixed` class:

1.  **In the `Fixed(const int decimal)` constructor:**
    ```cpp
    this->fixedPoint = decimal << Fixed::FRACTIONAL_BITS;
    ```
    Here, `decimal` (an integer like `10`) is directly left-shifted by `Fixed::FRACTIONAL_BITS` (which is 8).
    This effectively multiplies `decimal` by `2^8` (256).
    So, `10` becomes `10 * 256 = 2560`.
    This `2560` is the fixed-point representation of `10.0`. The original `10` is now in the "integer part" of the `fixedPoint` variable, and the lower 8 bits are all zeros, representing the `.0` fractional part.

2.  **In the `Fixed(const float real)` constructor (the `(1 << Fixed::FRACTIONAL_BITS)` part):**
    ```cpp
    this->fixedPoint = roundf(real * (1 << Fixed::FRACTIONAL_BITS));
    ```
    Here, `(1 << Fixed::FRACTIONAL_BITS)` is used to *calculate* the multiplier `2^8` (256).
    So, `1 << 8` evaluates to `256`.
    Then, `real` (e.g., `42.42f`) is multiplied by this `256`.
    `42.42 * 256 = 10859.52`.
    `roundf()` then rounds this to `10860`.
    This `10860` is the fixed-point representation of `42.42`. The multiplication scales the floating-point number up so that its integer and fractional parts can be stored within the single `fixedPoint` integer, with the lower 8 bits now representing the fractional part.

---

### Output Explanation

| `main.cpp` Line | Output & Explanation |
|---|---|
| `Fixed a;` | **Output:** `Default constructor called`<br>**Explanation:** Initializes object `a` using the default constructor. |
| `Fixed const b( 10 );` | **Output:** `Int constructor called`<br>**Explanation:** Initializes object `b` using the `int` constructor, converting `10` to its fixed-point representation. |
| `Fixed const c( 42.42f );` | **Output:** `Float constructor called`<br>**Explanation:** Initializes object `c` using the `float` constructor, converting `42.42f` to its fixed-point representation. |
| `Fixed const d( b );` | **Output:** `Copy constructor called`<br>**Explanation:** Initializes object `d` by copying object `b`. |
| `a = Fixed( 1234.4321f );` | **Output:**<br>`Float constructor called`<br>`Copy assignment operator called`<br>`Destructor called`<br>**Explanation:** A temporary `Fixed` object is created with the `float` constructor, then assigned to `a` using the copy assignment operator. The temporary object is then immediately destroyed. |
| `std::cout << "a is " << a << std::endl;` | **Output:** `a is 1234.43`<br>**Explanation:** Calls the overloaded `operator<<`, which uses `a.toFloat()` to print the value. |
| `std::cout << "b is " << b << std::endl;` | **Output:** `b is 10`<br>**Explanation:** Prints the floating-point representation of `b`. |
| `std::cout << "c is " << c << std::endl;` | **Output:** `c is 42.4219`<br>**Explanation:** Prints the floating-point representation of `c`. The value is the closest float representation after conversion. |
| `std::cout << "d is " << d << std::endl;` | **Output:** `d is 10`<br>**Explanation:** Prints the floating-point representation of `d` (a copy of `b`). |
| `std::cout << "a is " << a.toInt() << " as integer" << std::endl;` | **Output:** `a is 1234 as integer`<br>**Explanation:** Calls `a.toInt()` to convert the fixed-point value to an integer, truncating the fractional part. |
| `std::cout << "b is " << b.toInt() << " as integer" << std::endl;` | **Output:** `b is 10 as integer`<br>**Explanation:** Calls `b.toInt()` to get the integer part of `b`. |
| `std::cout << "c is " << c.toInt() << " as integer" << std::endl;` | **Output:** `c is 42 as integer`<br>**Explanation:** Calls `c.toInt()` to get the integer part of `c`. |
| `std::cout << "d is " << d.toInt() << " as integer" << std::endl;` | **Output:** `d is 10 as integer`<br>**Explanation:** Calls `d.toInt()` to get the integer part of `d`. |
| `return (0);` (End of `main`) | **Output:**<br>`Destructor called`<br>`Destructor called`<br>`Destructor called`<br>`Destructor called`<br>**Explanation:** The `Fixed` objects `a`, `b`, `c`, and `d` go out of scope and are destroyed in the reverse order of their creation. |
