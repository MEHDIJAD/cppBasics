# Notes on ex00

## Question: Why did we need a get function for hit points but not for others like energy?

That's an excellent and very important question in object-oriented programming.

The short answer is: **No, you should definitely not create a public getter and setter for every private variable.**

Doing so is often considered a bad practice because it breaks the principle of **encapsulation**. The whole point of making variables `private` is to protect the internal state of your object and control how it's modified.

Here’s how to think about it:

1.  **Getters (Accessors):** Only create a `getter` if the outside world genuinely needs to **read** that specific piece of information. In our case, `main.cpp` needs to read the hit points to check if the `takeDamage` function worked, so `getHitPoints()` makes sense.

2.  **Setters (Mutators):** Be very careful with `setters`. You should only create a `setter` if you want to give the outside world **direct, uncontrolled access** to change a variable. Most of the time, you want to control *how* a variable changes.

Let's look at `ClapTrap` again:

*   **Why no `setHitPoints()`?** Because you shouldn't be able to just set a `ClapTrap`'s health to any number you want. Health should only change in specific, controlled ways: through the `takeDamage()` and `beRepaired()` methods. This protects the object's logic.
*   **Why no `setEnergyPoints()`?** Same reason. Energy should only decrease when an action like `attack()` or `beRepaired()` is performed.

**The Golden Rule:**

Instead of automatically adding getters and setters, think about the **behaviors** of your object. Ask yourself:

*   What does this object *do*? (e.g., `attack`, `beRepaired`). These are your public methods.
*   What information does the outside world *need* from it? (This will tell you if you need a `getter`).
*   How should the object's internal state *change*? (These changes should happen inside your public methods, not through simple `setters`).

So, to summarize: **Depend on the needs of your program, not on a rule of creating getters and setters for everything.** You've stumbled upon a core concept of good class design.

---

## Question: What if we give the amount damage as negative, will the code crash?

That's a very sharp question. The code will **not crash**, but it will have an unexpected and incorrect behavior due to how C++ handles data types.

Let's look at the function signature in `ClapTrap.hpp`:

```cpp
void takeDamage(unsigned int amount);
```

The `amount` parameter is an `unsigned int`. The `unsigned` keyword means this integer cannot be negative; its range is from 0 to a very large positive number (e.g., 4,294,967,295 on a 32-bit system).

If you try to pass a negative number like `-5` to this function, the compiler will perform an implicit conversion. The negative number will "wrap around" and become a very large positive `unsigned int`.

For example, `-5` would become `4294967291`.

So, when your `takeDamage` function executes, it will receive this huge number as the `amount`. The logic inside the function will then execute:

```cpp
if (this->_HitPoint < amount) // This will be true (e.g., 10 < 4294967291)
    this->_HitPoint = 0;      // _HitPoint will be set to 0
else
    this->_HitPoint -= amount;
```

**The result is that the ClapTrap's hit points will be immediately set to 0.**

So, while it doesn't crash the program, it's a serious logical bug. This is a great example of why using the correct data types is so important and why you should always pay attention to compiler warnings, as the compiler would likely warn you about this problematic conversion.

---

## Question: Why do `attack` and `beRepaired` have two conditions, but `takeDamage` only has one?

That's another excellent question that gets to the heart of the object's logic. The difference is based on what the functions represent: **actions the ClapTrap performs** versus **things that happen to the ClapTrap**.

### `attack()` and `beRepaired()` - Active Actions

These are actions that the `ClapTrap` actively chooses to do. For it to perform any action, two things must be true:

1.  **It must be "alive"** (have more than 0 hit points). A defeated `ClapTrap` can't do anything.
2.  **It must have energy** to perform the action. Both attacking and repairing cost 1 energy point.

That's why both functions check `if (this->_HitPoint == 0 || this->_EnergyPoint == 0)`. If either of these is true, the action cannot be performed.

### `takeDamage()` - A Passive Event

This function represents something that **happens to** the `ClapTrap`. It's not an action the `ClapTrap` chooses. An enemy can attack it regardless of how much energy it has.

Therefore, the only condition that matters is:

1.  **Is the `ClapTrap` already defeated?** (`_HitPoint == 0`). If it's already at 0 HP, it can't take any more damage. There's no need to check for energy because taking damage doesn't consume energy.

**In short:**

*   **`attack` / `beRepaired`:** Checks for **health AND energy** because they are actions that require both to be performed.
*   **`takeDamage`:** Only checks for **health** because it's a passive event that doesn't depend on the `ClapTrap`'s energy level.