#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
    : AMateria("cure")
{
    std::cout << "[Cure] Default constructor called" << std::endl;
}

Cure::Cure(Cure const & src)
    : AMateria(src)
{
    std::cout << "[Cure] Copy constructor called" << std::endl;
    *this = src; // same reasoning
}

Cure & Cure::operator=(Cure const & rhs)
{
    std::cout << "[Cure] Assignment operator called" << std::endl;
    (void)rhs;
    return *this;
}

Cure::~Cure()
{
    std::cout << "[Cure] Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    // Return a new instance of the same type
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    // According to the subject:
    // "* heals <name>’s wounds *"
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

