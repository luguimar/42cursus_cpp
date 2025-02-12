#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    // Default constructor
    FragTrap();
    // Constructors and Destructor (Orthodox Canonical Form)
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    // Overridden attack method
    void attack(const std::string &target);

    // Special member function for FragTrap
    void highFivesGuys(void);
};

#endif
