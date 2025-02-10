#include "Zombie.hpp"
#include <iostream>

// Constructor initializes the Zombie's name
Zombie::Zombie(std::string name) : _name(name) {}

// Destructor prints a debug message
Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

// Zombie announces itself
void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
