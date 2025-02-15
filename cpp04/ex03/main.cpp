#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << "Equipping pointer: " << tmp << std::endl;
    tmp = src->createMateria("cure");
    std::cout << "Equipping pointer: " << tmp << std::endl;
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    *me = *bob;

    me->use(0, *bob);
    me->use(1, *bob);
    
    me->unequip(1);

    me->use(1, *bob);


    delete tmp;
    delete bob;
    delete me;
    delete src;

    return 0;
}
