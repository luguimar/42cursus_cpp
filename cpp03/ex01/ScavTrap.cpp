#include "ScavTrap.hpp"

// Default constructor: calls ClapTrap's default constructor and then resets attributes.
ScavTrap::ScavTrap() : ClapTrap() {
    // Update base attributes with new values for ScavTrap.
    // (Make sure these members are declared as protected in ClapTrap.)
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

// Constructor: calls ClapTrap's constructor and then resets attributes.
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    // Update base attributes with new values for ScavTrap.
    // (Make sure these members are declared as protected in ClapTrap.)
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " destructed." << std::endl;
}

// Overridden attack() function
void ScavTrap::attack(const std::string &target) {
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
        std::cout << "ScavTrap " << this->_name
                  << " cannot attack because it has no hit points or energy left." 
                  << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!" 
              << std::endl;
}

// Unique member function: guardGate()
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name 
              << " is now in Gate keeper mode." << std::endl;
}
