#include "FragTrap.hpp"
#include <iostream>

// Constructor: Calls the base ClapTrap constructor, then resets attributes.
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    // Update attributes specific to FragTrap.
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructed." << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " destructed." << std::endl;
}

// Overridden attack() function
void FragTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->_name
                  << " cannot attack because it has no hit points or energy left." 
                  << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage!" 
              << std::endl;
}

// Unique member function: highFivesGuys()
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name 
              << " requests a high five! Positive vibes only!" 
              << std::endl;
}
