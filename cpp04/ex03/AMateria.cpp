#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    // std::cout << "AMateria constructor called with type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
    // std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignment: copying the type doesn’t make sense per the subject’s note
AMateria &AMateria::operator=(const AMateria &other) {
    // std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other) {
        // We do NOT copy the _type based on instructions.
        // _type = other._type; <-- The subject says it's nonsense to copy type
    }
    return *this;
}

AMateria::~AMateria() {
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    // Default usage message (can be overridden by derived classes)
    std::cout << "* uses an unknown materia at " << target.getName() << " *" << std::endl;
}
