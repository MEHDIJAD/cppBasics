# Notes on Inheritance Types

## Question: The inheritance will be public, right? How to know what type?


### What are the types of inheritance?

In C++, when a class inherits from another, you specify an access specifier: `public`, `protected`, or `private`. This controls how the base class's members (public, protected) are accessed within the derived class and by outside code.

1.  **`public` inheritance:**
    *   `public` members of the base class remain `public` in the derived class.
    *   `protected` members of the base class remain `protected` in the derived class.
    *   `private` members of the base class are never directly accessible.
    *   **This is the most common type** and models an "is-a" relationship (e.g., a `ScavTrap` **is a** `ClapTrap`). It means the derived class maintains the public interface of the base class.

2.  **`protected` inheritance:**
    *   `public` members of the base class become `protected` in the derived class.
    *   `protected` members of the base class remain `protected` in the derived class.
    *   `private` members are never directly accessible.
    *   This is less common. The base class's public interface is hidden from outside the derived class but accessible to further derived classes.

3.  **`private` inheritance:**
    *   `public` members of the base class become `private` in the derived class.
    *   `protected` members of the base class become `private` in the derived class.
    *   `private` members are never directly accessible.
    *   This is also less common and often used for "implemented-in-terms-of" relationships, similar to composition. The base class's entire interface becomes private to the derived class.

### How to know what type to use?

The general rule of thumb is to use `public` inheritance unless you have a very specific reason not to.

*   **If the derived class "is a" type of the base class, use `public` inheritance.** This is the most intuitive and common use case, allowing polymorphism (treating a derived class object as a base class object).
*   If you want to reuse the implementation of the base class but hide its interface from the outside world, you might consider `private` inheritance or, more commonly, **composition** (where one class contains an object of another class).

### For `ScavTrap` and `ClapTrap`:

The problem description states that `ScavTrap` is a "derived robot" and will "inherit the constructors and destructor from ClapTrap," and "ScavTrap will use the attributes of ClapTrap." This strongly suggests an "is-a" relationship: a `ScavTrap` is a more specialized kind of `ClapTrap`.

Therefore, **`public` inheritance is the correct and most appropriate choice** for `ScavTrap` inheriting from `ClapTrap`. This will allow `ScavTrap` to use `ClapTrap`'s public methods (`attack`, `takeDamage`, `beRepaired`) while also adding its own unique features.

---

### Inheritance Access Specifiers Summary

| Base Class Member Access | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
| :----------------------- | :------------------- | :---------------------- | :-------------------- |
| `public`                 | `public`             | `protected`             | `private`             |
| `protected`              | `protected`          | `protected`             | `private`             |
| `private`                | Not accessible       | Not accessible          | Not accessible        |

---


## Question: I added a default constructor to the ClapTrap. So, in general, when I create a derived class, does the default constructor for the derived class need a default for the parent, and a parameterized constructor need a parameterized for the parent?

That's a great question, and you're very close to the right idea. Adding a default constructor to `ClapTrap` does fix the error, but let's clarify the general rule, because it's more flexible than you might think.

### The Golden Rule of Derived Constructors

Here is the most important rule: **A derived class constructor MUST always call a base class constructor.**

The question is, *which* one does it call?

1.  **The Implicit Call:** If you **do not** explicitly tell the derived constructor which base constructor to use (with an initializer list), the compiler will **always** try to call the **default (parameterless) constructor** of the base class.

    This is what happened to you. Your `ScavTrap` constructor didn't specify a `ClapTrap` constructor, so it tried to call `ClapTrap()`, which didn't exist initially. Your fix worked because you gave the compiler the `ClapTrap()` it was looking for.

2.  **The Explicit Call (The Better Way):** You can, and often should, explicitly choose which base constructor to call.

This is where your question gets interesting:

> "parametrize need parametrize for parent ??"

Not necessarily! A parameterized constructor in the derived class can call **any** available constructor in the parent class.

### Examples

Let's assume `ClapTrap` now has both constructors:
`ClapTrap();`
`ClapTrap(std::string name);`

Here are the possibilities for `ScavTrap`:

**Possibility 1: Derived default calls Base default** (This is the implicit case)
```cpp
// This will automatically call ClapTrap()
ScavTrap::ScavTrap() {
    // ...
}
```

**Possibility 2: Derived parameterized calls Base default**
```cpp
// This will also automatically call ClapTrap() because we didn't specify otherwise.
// The 'hitPoints' parameter is only used by ScavTrap.
ScavTrap::ScavTrap(int hitPoints) {
    this->_HitPoint = hitPoints;
    // ...
}
```

**Possibility 3: Derived parameterized calls Base parameterized** (This is the most common and powerful pattern)
```cpp
// Here, we explicitly forward the 'name' to the ClapTrap constructor.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { // <-- THIS IS THE FIX
    // ...
}
```

### Summary

*   A derived constructor **doesn't** have to match the parent constructor's signature.
*   You have the power to decide which parent constructor is the right one to call from any of your derived constructors.
*   If you don't make a choice, the compiler defaults to calling the parent's default `()` constructor.

While adding a default constructor to `ClapTrap` works, the "better" and more flexible solution to your original problem is to use the initializer list to explicitly call the `ClapTrap(std::string name)` constructor, as shown in Possibility 3.

---

## Question: Why the destructor of the derived class happens before the parent class?

That's an excellent question. It happens in that order for a very important reason: **to prevent errors during cleanup.**

Think of it like building and demolishing a building:

1.  **Construction (Building Up):** You must build the foundation (`ClapTrap`) **before** you can build the main floor (`ScavTrap`). If you did it the other way, the floor would have nothing to stand on.
    *   **Order:** `ClapTrap` constructor -> `ScavTrap` constructor.

2.  **Destruction (Tearing Down):** You must demolish the main floor (`ScavTrap`) **before** you can demolish the foundation (`ClapTrap`). The `ScavTrap`'s cleanup code might still need to use parts of the `ClapTrap`, so the `ClapTrap` must be the last thing to be destroyed.
    *   **Order:** `ScavTrap` destructor -> `ClapTrap` destructor.

In short, C++ guarantees that an object is destroyed in the exact reverse order that it was constructed. This ensures that a derived class can safely perform its cleanup while the base class it depends on is still fully intact.

---

## Question: Can I initialize protected members in the initializer list in a derived class constructor?

No, you cannot directly initialize inherited `protected` members in the derived class's initializer list (`: member(value)`).

The initializer list is for:
1.  Calling the base class constructor.
2.  Initializing the derived class's *own* members.

You must set the values in the derived class constructor's **body**, after the base class constructor has run.