#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Constructors and destructor (Orthodox Canonical Form)
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    // Overridden member function
    void attack(const std::string &target);

    // Unique member function for ScavTrap
    void guardGate();
};

#endif
