#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    // Constructor / Destructor
    Zombie(std::string name);
    ~Zombie();

    // Member function
    void announce(void);
};

#endif

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
