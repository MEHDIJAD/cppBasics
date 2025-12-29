#include "incl/AMateria.hpp"
#include "incl/Ice.hpp"
#include "incl/Cure.hpp"
#include "incl/Character.hpp"
#include "incl/IMateriaSource.hpp"
#include "incl/MateriaSource.hpp"

void TestSubject()
{
    std::cout << BLUE << "\n=== TEST 1: SUBJECT BASIC TEST ===" << RESET << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

void TestDeepCopy()
{
    std::cout << YELLOW << "\n=== TEST 2: DEEP COPY CHECK ===" << RESET << std::endl;
    // 1. Create original character and equip stuff
    Character* original = new Character("Original");
    AMateria* m1 = new Ice();
    original->equip(m1);

    // 2. Create copy using Copy Constructor
    Character* copy = new Character(*original);

    // 3. Delete original (If shallow copy, 'copy' will crash when used/deleted)
    delete original;

    // 4. Verify copy still works (Its inventory should be independent)
    std::cout << GREEN<< "Using copy (should work even after original is deleted):" << std::endl;
    ICharacter* target = new Character("Target");
    copy->use(0, *target); // Should shoot ice

    delete target;
    delete copy;
}

void TestInventoryFull()
{
    std::cout << BLUE << "\n=== TEST 3: FULL INVENTORY & LEAK CHECK ===" << RESET << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice()); // 0
    src->learnMateria(new Cure()); // 1
    src->learnMateria(new Ice()); // 2
    src->learnMateria(new Cure()); // 3
    
    // This 5th one should be DELETED by learnMateria automatically
    // If valgrind/leaks shows a leak here, check your learnMateria logic!
    src->learnMateria(new Ice()); // 4 (Overflow)

    Character* me = new Character("Me");
    
    // Equip 4 items
    for (int i = 0; i < 4; i++)
        me->equip(src->createMateria("ice"));

    // Try to equip 5th item. 
    // Character::equip MUST delete this extra item, or it leaks.
    AMateria* extra = src->createMateria("cure");
    me->equip(extra); 

    delete me;
    delete src;
}

void TestUnequip()
{
    std::cout << BLUE << "\n=== TEST 4: UNEQUIP (FLOOR) CHECK ===" << RESET << std::endl;
    ICharacter* me = new Character("Me");
    AMateria* ice = new Ice();
    
    me->equip(ice);

    // To unequip safely, we must know the pointer address to delete it later
    // In this test, we already have 'ice' pointer.
    
    me->unequip(0); // Removing from inventory
    
    // Using unequipped slot should do nothing
    ICharacter* bob = new Character("Bob");
    me->use(0, *bob); 

    // CLEANUP THE FLOOR
    // If we don't delete 'ice' here, it's a leak because Character no longer owns it
    delete ice; 

    delete bob;
    delete me;
}


int main()
{
	TestSubject();
	TestDeepCopy();
	TestInventoryFull();
    TestUnequip();
	return 0;
}