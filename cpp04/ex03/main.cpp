#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
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
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); // "* shoots an ice bolt at bob *"
    me->use(1, *bob); // "* heals bob's wounds *"

    // Optional: test unequip
    me->unequip(0);
    me->use(0, *bob); // Now slot 0 is empty, no output

    delete bob;
    delete me;
    delete src;

    return 0;
}
