#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
    : _type("amateria")
{
    std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
    : _type(type)
{
    std::cout << "[AMateria] Parameter constructor called with type: " << type << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "[AMateria] Copy constructor called" << std::endl;
    *this = src; // Calls operator=
}

AMateria & AMateria::operator=(AMateria const &rhs)
{
    std::cout << "[AMateria] Assignment operator called" << std::endl;
    // According to the subject, copying the _type doesn't make sense when
    // assigning Materias. We do NOT copy the type.
    (void)rhs;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "[AMateria] Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "[AMateria] Using unknown Materia on " << target.getName() << std::endl;
}

