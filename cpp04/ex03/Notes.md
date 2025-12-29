### Learning Purpose of `ex03`

The exercise is designed to teach you two main things:

1.  **Interfaces:** How to write flexible code that relies on abstract contracts (`ICharacter`, `IMateriaSource`) rather than concrete classes. This is a fundamental principle of good object-oriented design.
2.  **Memory Ownership:** This is the most critical part. The exercise creates complex rules to force you to think about who is responsible for `delete`ing every object created with `new`. The `unequip()` rule, in particular, is a classic example of a "trap" to make you consider what happens when ownership of a pointer is abandoned.
