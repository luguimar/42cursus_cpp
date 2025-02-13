#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Using proper polymorphism:
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;  // Should print "Dog"
    std::cout << i->getType() << " " << std::endl;  // Should print "Cat"

    i->makeSound(); // Expected: "Meow! Meow!"
    j->makeSound(); // Expected: "Woof! Woof!"
    meta->makeSound(); // Expected: "Some generic animal sound"

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "----- Wrong Animal Test -----" << std::endl;
    
    // Using the wrong hierarchy (non-virtual makeSound)
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;  // Should print "WrongCat"
    // Even though WrongCat overrides makeSound(), because the base method is not virtual,
    // this call will use WrongAnimal::makeSound().
    wrongCat->makeSound(); // Expected: "Some generic wrong animal sound"

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
