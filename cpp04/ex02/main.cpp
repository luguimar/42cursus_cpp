#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int arraySize = 4;
    Animal* animals[arraySize];

    // Create an array of Animal pointers: first half Dogs, second half Cats.
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n-- Animals making sounds --" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    // Test deep copy: copy a Dog, then delete the original and ensure the copy remains independent.
    std::cout << "\n-- Testing deep copy for Dog --" << std::endl;
    Dog* original = new Dog();
    std::cout << "Original Dog makes sound: ";
    original->makeSound();

    Dog* copyDog = new Dog(*original);
    delete original;
    std::cout << "Copy of Dog makes sound (after deleting original): ";
    copyDog->makeSound();
    delete copyDog;

    // Delete all animals (will call the proper destructors)
    std::cout << "\n-- Deleting Animal array --" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

//    Animal a;
    return 0;
}

