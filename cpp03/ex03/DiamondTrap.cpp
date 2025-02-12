#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    // Initialize the unique ClapTrap subobject with name + "_clap_name"
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    // Set attributes from the corresponding parent classes:
    // Hit points and Attack Damage from FragTrap, Energy points from ScavTrap.
    this->_hitPoints = 100;    // FragTrap value
    this->_energyPoints = 50;  // ScavTrap value
    this->_attackDamage = 30;  // FragTrap value

    std::cout << "DiamondTrap " << _name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called." << std::endl;
    if (this != &other)
    {
        // Assign the ClapTrap part (shared via virtual inheritance)
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
    // Access ClapTrap::_name (ensure that _name in ClapTrap is declared as protected)
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
