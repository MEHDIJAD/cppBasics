# C++ Module 04: Subtype Polymorphism

## Virtual Functions
- **Static Binding**: Compiler decides which function to call (default).
- **Dynamic Binding**: Runtime decides based on the actual object type.
- **Keyword**: `virtual`.
    - If `Animal::makeSound()` is virtual, `Animal* ptr = new Dog(); ptr->makeSound()` calls "Bark", not generic animal sound.

## Abstract Classes & Interfaces
- **Pure Virtual**: `virtual void func() = 0;`
- **Abstract Class**: Has at least one pure virtual function. Cannot be instantiated directly.
- **Interface**: A class with *only* pure virtual functions (no data members usually).

## Deep Copy (Brain)
- **Problem**: Default copy just copies the pointer address (Shallow Copy). If one object is deleted, the other points to garbage.
- **Solution**:
    - Allocate **new** memory in Copy Constructor and Assignment Operator.
    - Copy the *content*, not just the address.

## Project: Brain & Materia

### Ex01/Ex02: Animal & Brain
- **Brain Class**: Contains array of 100 ideas (`std::string ideas[100]`).
- **Deep Copy**:
    - In `Dog` copy constructor, I created `this->brain = new Brain(*other.brain);`.
- **Virtual Destructor**: Crucial! `virtual ~Animal()` ensures `~Dog()` is called when deleting an `Animal*`.

### Ex03: Interface (Materia)
- **AMateria**: Abstract base class.
- **MateriaSource**: The "Factory".
    - Learns templates (`learnMateria`).
    - Creates new copies (`createMateria`).
- **Character**: Uses an Inventory (`AMateria* inventory[4]`).
    - `equip()`: Takes ownership of a pointer.
    - `unequip()`: Removes from inventory but does *not* delete (caller responsibility).
