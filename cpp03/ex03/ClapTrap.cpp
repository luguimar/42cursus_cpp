#include "ClapTrap.hpp"

// Default constructor: initializes the ClapTrap with default values.
ClapTrap::ClapTrap()
    : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

// Constructor: initializes the ClapTrap with the provided name and default values.
ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructed." << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
    *this = other;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

// attack(): Decrements energy points and displays an attack message.
void ClapTrap::attack(const std::string &target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points or energy left." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// takeDamage(): Reduces hit points by the damage amount.
void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
        return;
    }
    _hitPoints -= static_cast<int>(amount);
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Hit points: " << _hitPoints << std::endl;
}

// beRepaired(): Uses 1 energy point to regain hit points.
void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair itself because it has no hit points or energy left." << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += static_cast<int>(amount);
    std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount
              << " hit points! Hit points: " << _hitPoints << std::endl;
}
