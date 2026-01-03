# C++ Module 03: Inheritance

## Inheritance Types
- **Public (`: public Parent`)**: "Is-a" relationship. Public members of parent stay public.
- **Protected (`protected:`)**: Accessible by children, but private to the outside world.
- **Construction Order**: Parent built first -> Child built second.
- **Destruction Order**: Child destroyed first -> Parent destroyed last.

## The Diamond Problem (Ex03)
- **Scenario**: `DiamondTrap` inherits from both `ScavTrap` and `FragTrap`, which both inherit from `ClapTrap`.
- **Issue**: `DiamondTrap` would have *two* copies of `ClapTrap` (Ambiguity).
- **Solution**: **Virtual Inheritance**.
    - `class ScavTrap : virtual public ClapTrap`
    - `class FragTrap : virtual public ClapTrap`
    - Ensures only one instance of the grandparent (`ClapTrap`) exists.

## Project: ClapTrap / ScavTrap / FragTrap

### ClapTrap (Base)
- Implements basic game logic: `HitPoints`, `EnergyPoints`, `AttackDamage`.
- **Notes**: Constructors print messages to prove the chaining order.

### ScavTrap
- Adds `guardGate()` mode.
- Overrides `attack()` (uses different message/logic).

### DiamondTrap (The Monster)
- Inherits from both Scav and Frag.
- **Scoping**: Needs to explicitly call functions from specific parents if ambiguous.
    - `ScavTrap::attack()`
- **Shadowing**: Has its own `_name` private variable, shadowing `ClapTrap::_name`.
