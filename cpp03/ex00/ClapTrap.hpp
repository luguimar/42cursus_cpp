#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

public:
    // Default constructor
    ClapTrap();
    // Constructor that takes a name as parameter
    ClapTrap(const std::string &name);
    // Copy constructor
    ClapTrap(const ClapTrap &other);
    // Copy assignment operator
    ClapTrap &operator=(const ClapTrap &other);
    // Destructor
    ~ClapTrap();

    // Member functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
