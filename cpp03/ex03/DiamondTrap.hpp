#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    // This overshadows ClapTrap::_name
    std::string _name;

public:
    // Default constructor
    DiamondTrap();
    // Constructors & Destructor (Orthodox Canonical Form)
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void attack(const std::string &target);

    void whoAmI();
};

#endif
