#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie();                     // Default constructor
    Zombie(std::string name);     // Parametrized constructor
    ~Zombie();                    // Destructor

    void announce() const;        // Announces itself
    void setName(std::string name);
};

#endif

// Declare the function so main.cpp knows it exists
Zombie* zombieHorde(int N, std::string name);

