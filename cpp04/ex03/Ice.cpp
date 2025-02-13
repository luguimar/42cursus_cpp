#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
    // std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice() {
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    // Return a new instance of Ice
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
