
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
    : AMateria("ice")
{
    std::cout << "[Ice] Default constructor called" << std::endl;
}

Ice::Ice(Ice const & src)
    : AMateria(src)
{
    std::cout << "[Ice] Copy constructor called" << std::endl;
    *this = src; // safe to do, though it doesn't copy type anyway
}

Ice & Ice::operator=(Ice const & rhs)
{
    std::cout << "[Ice] Assignment operator called" << std::endl;
    // We do not copy the type, same reasoning as AMateria.
    // No extra data in Ice to copy. 
    (void)rhs;
    return *this;
}

Ice::~Ice()
{
    std::cout << "[Ice] Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    // Return a new instance of the same type
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    // According to the subject:
    // "* shoots an ice bolt at <name> *"
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

