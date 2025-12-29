#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/Brain.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

void Test1(void)
{
	// =========================================================================
    // TEST 1: SUBJECT TESTS (Basic Polymorphism)
    // =========================================================================
    std::cout << BLUE << "=== TEST 1: SUBJECT TESTS ===" << RESET << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
}

void Test2(void)
{
	// ========================================================================
    // TEST 2: The Subject Requirement (Array of Animals)
    // ========================================================================
    std::cout << BLUE << "\n\n=== TEST 2: ARRAY OF ANIMALS ===" << RESET << std::endl;

	const int arraySize = 4;
	const Animal *animals[arraySize];
	
	for (int i = 0; i < arraySize / 2; i++){
		animals[i] = new Dog();
	}
	for (int i = arraySize / 2; i < arraySize; i++){
		animals[i] = new Cat();
	}

	std::cout << "\n" << RED << "=== DELETING ARRAY ===" << RESET << std::endl;

	for (int i = 0; i < arraySize; i++){
		delete animals[i];
	}
	std::cout << std::endl;
}

void Test3(void)
{
    // ========================================================================
    // TEST 3: Deep Copy Proof (Copy Constructor)
    // ========================================================================
    std::cout << "\n" << BLUE << "=== TEST 3: DEEP COPY (CONSTRUCTOR) ===" << RESET << std::endl;

    Dog *original = new Dog();
    original->setIdea(0, "I want to chase the ball!"); // 1. Set specific idea
    
    std::cout << BLUE << "Original Idea: " << original->getIdea(0) << RESET << std::endl;
    
    Dog *copy = new Dog(*original); // 2. Create copy
    std::cout << GRAY << "Copy created.\n" << RESET;

    // 3. CHANGE Original's idea
    original->setIdea(0, "Actually, I want to sleep...");
    std::cout << BLUE << "Original Idea Changed to: " << original->getIdea(0) << RESET << std::endl;

    // 4. VERIFY Copy (Should remain "chase the ball")
    std::cout << GREEN << "Copy's Idea (Should be 'chase the ball'): " << copy->getIdea(0) << RESET << std::endl;

    if (copy->getIdea(0) != original->getIdea(0))
        std::cout << GREEN << "SUCCESS: Deep Copy confirmed!" << RESET << std::endl;
    else
        std::cout << RED << "FAILED: Shallow Copy detected!" << RESET << std::endl;

    delete original; 
    delete copy; 
}

void Test4(void)
{
    // ========================================================================
    // TEST 4: Assignment Operator (Brain Transplant)
    // ========================================================================
    std::cout << "\n" << BLUE << "=== TEST 4: ASSIGNMENT OPERATOR ===" << RESET << std::endl;

    Dog dogA;
    Dog dogB;

    dogA.setIdea(0, "Hungry for bone");
    dogB.setIdea(0, "Empty head");

    std::cout << BLUE << "\nAssigning B = A...\n\n" << RESET;
    dogB = dogA; // Assignment happens here

    // Change A again
    dogA.setIdea(0, "Full now");

    // Check B
    std::cout << "DogA Idea: " << dogA.getIdea(0) << std::endl;
    std::cout << "DogB Idea: " << dogB.getIdea(0) << " (Should still be 'Hungry for bone')" << std::endl;
}

void TestAbstract(void)
{
    std::cout << BLUE << "\n=== TEST 5: ABSTRACT CLASS CHECK ===" << RESET << std::endl;

    // -------------------------------------------------------
    // [Manual Test]
    // Uncomment the line below. 
    // If your Animal class is properly Abstract, the compiler 
    // MUST throw an error like: "cannot allocate an object of abstract type 'Animal'"
    // -------------------------------------------------------
    
    // Animal* test = new Animal(); // <--- UNCOMMENT TO CHECK ERROR
    
    std::cout << "1. Cannot instantiate Animal directly? ";
    std::cout << GREEN << "[Confirmed if compiled with line commented]" << RESET << std::endl;

    // -------------------------------------------------------
    // [Functionality Test]
    // Even though Animal is abstract, we can still use pointers to it!
    // This proves the contract is working.
    // -------------------------------------------------------
    
    std::cout << "2. Can we still use Animal* pointers? \n";
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << GREEN << "Yes!" << RESET << std::endl;

    std::cout << "3. Do they still sound right?" << std::endl;
    std::cout << "Dog: "; dog->makeSound();
    std::cout << "Cat: "; cat->makeSound();

    delete dog;
    delete cat;
}

int main(void)
{
	Test1();
	Test2();
	Test3();
	Test4();
	TestAbstract();

	return 0;
}