#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name; // DiamondTrap's own name (same variable name as in ClapTrap)
public:
    // Orthodox Canonical Form
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    // Unique member function
    void whoAmI();
    // Note: DiamondTrap uses ScavTrap::attack() (inherited from ScavTrap)
};

#endif
