#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap() 
    : ClapTrap("default_clap_name"), 
      ScavTrap("default_clap_name"), 
      FragTrap("default_clap_name"),
      _name("default_name") 
{
    // According to the exercise:
    //  - Hit points: 100 (from FragTrap)
    //  - Energy points: 50 (from ScavTrap)
    //  - Attack damage: 30 (from FragTrap)
    _hitPoints = FragTrap::_hitPoints;     // 100
    _energyPoints = ScavTrap::_energyPoints;  // 50
    _attackDamage = FragTrap::_attackDamage;  // 30

    std::cout << "DiamondTrap " << _name
              << " constructed. (ClapTrap name: "
              << ClapTrap::_name << ")" << std::endl;
}

// 1) DiamondTrap(const std::string &name)
//    We call the base class constructors. ClapTrap will be constructed
//    through both FragTrap and ScavTrap, but we set the ClapTrap::_name
//    to (name + "_clap_name").
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), 
      ScavTrap(name + "_clap_name"), 
      FragTrap(name + "_clap_name"),
      _name(name) // Our own DiamondTrap::_name
{
    // According to the exercise:
    //  - Hit points: 100 (from FragTrap)
    //  - Energy points: 50 (from ScavTrap)
    //  - Attack damage: 30 (from FragTrap)
    _hitPoints = FragTrap::_hitPoints;     // 100
    _energyPoints = ScavTrap::_energyPoints;  // 50
    _attackDamage = FragTrap::_attackDamage;  // 30

    std::cout << "DiamondTrap " << _name
              << " constructed. (ClapTrap name: "
              << ClapTrap::_name << ")" << std::endl;
}

// 2) Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) 
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = other; 
}

// 3) Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        // We can reuse the base assignment operators
        ClapTrap::operator=(other);
        // Or ScavTrap::operator=(other), FragTrap::operator=(other) 
        // but typically ClapTrap is enough if everything is consistent.

        _name = other._name;
        // Reassign the stats:
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// 4) Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name
              << " destructed. (ClapTrap name: "
              << ClapTrap::_name << ")" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

// whoAmI() -> prints the DiamondTrap's own name and the ClapTrap name
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name
              << " and my ClapTrap name is "
              << ClapTrap::_name << "." << std::endl;
}

