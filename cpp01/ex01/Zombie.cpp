#include "Zombie.hpp"
#include <iostream>

// Default constructor
Zombie::Zombie() : _name("UnnamedZombie") {}

// Parametrized constructor
Zombie::Zombie(std::string name) : _name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " is destroyed" << std::endl;
}

// Set the zombie's name (used for the horde initialization)
void Zombie::setName(std::string name) {
    _name = name;
}

// Announces itself
void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
