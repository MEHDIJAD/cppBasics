#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/WrongCat.hpp"
#include "incl/WrongAnimal.hpp"


void Test1(void)
{
	// =========================================================================
    // TEST 1: SUBJECT TESTS (Basic Polymorphism)
    // =========================================================================
    std::cout << BLUE << "=== TEST 1: SUBJECT TESTS ===" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout  << YELLOW << "j Type: " << RESET << j->getType() << " " << std::endl;
    std::cout << YELLOW << "i Type: " << RESET << i->getType() << " " << std::endl;
    
    std::cout << GREEN << "Expected: Cat Sound | Actual: ";
    i->makeSound(); // will output the cat sound!
    
    std::cout << BLUE << "Expected: Dog Sound | Actual: ";
    j->makeSound();

    std::cout << YELLOW << "Expected: Animal Sound | Actual: ";
    meta->makeSound();

    // Cleaning up (Checking destructors later)
    delete j;
    delete i;
    delete meta;
    std::cout << std::endl;

}

void Test2(void)
{
	// =========================================================================
    // TEST 2: VIRTUAL DESTRUCTOR CHECK
    // =========================================================================
    // If the destructor in Animal is NOT virtual, the Dog destructor will NOT be called.
    // Watch your terminal output closely here!
    std::cout << BLUE << "=== TEST 2: VIRTUAL DESTRUCTOR CHECK ===" << RESET << std::endl;
    
    const Animal* dog = new Dog();
    std::cout  << YELLOW << "Deleting a Dog object via an Animal pointer..." << std::endl;
    delete dog; // Should print "Dog Destructor" THEN "Animal Destructor"
    std::cout << std::endl;
}

void Test3(void)
{
	// =========================================================================
    // TEST 3: WRONG ANIMAL (Static Binding Demonstration)
    // =========================================================================
    // Proves that without 'virtual', the pointer type determines the function call.
    std::cout << BLUE << "=== TEST 3: WRONG ANIMAL TESTS ===" << RESET << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout  << GREEN << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;

    std::cout << RED << "Expected: WrongAnimal Sound (No Virtual) | Actual: ";
    wrongCat->makeSound(); // <--- THE BUG IS HERE (Intentionally)

    std::cout << RED << "Expected: WrongAnimal Sound | Actual: ";
    wrongMeta->makeSound();

    delete wrongCat;
    delete wrongMeta;
    std::cout << std::endl;

}

void Test04(void)
{
	// =========================================================================
    // TEST 4: DIRECT OBJECT VS POINTER (The "Hidden" Function)
    // =========================================================================
    // Proves that WrongCat DOES have a makeSound function, but the pointer hides it.
    std::cout << BLUE << "=== TEST 4: DIRECT INSTANTIATION VS POINTER ===" << RESET << std::endl;
    
    WrongCat rawCat; // Stack object
    std::cout << "Calling makeSound() on a raw WrongCat object: ";
    rawCat.makeSound(); // Works! Prints WrongCat sound.

    WrongAnimal* ptrToRaw = &rawCat;
    std::cout << "Calling makeSound() on WrongAnimal* pointing to same object: ";
    ptrToRaw->makeSound(); // Fails! Prints WrongAnimal sound.
    std::cout << std::endl;
}

void Test05(void)
{
	// =========================================================================
    // TEST 5: CANONICAL FORM (Copy Constructor)
    // =========================================================================
    std::cout << BLUE << "=== TEST 5: COPY CONSTRUCTOR BASICS ===" << RESET << std::endl;
    
    Dog originalDog;
    // Assume you have a setName or some distinct property if you implemented ex01 logic early
    Dog copyDog(originalDog);

    std::cout << "Original Type: " << originalDog.getType() << std::endl;
    std::cout << "Copy Type: " << copyDog.getType() << std::endl;
    
    std::cout << "Original Sound: "; originalDog.makeSound();
    std::cout << "Copy Sound: "; copyDog.makeSound();
    
    std::cout << std::endl;
}

int main(void)
{
	Test1();
	Test2();
	Test3();
	Test04();
	Test05();

	return 0;
}
