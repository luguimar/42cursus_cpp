#include "Zombie.hpp"

// Creates a zombie on the heap and returns its pointer
Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    return z;
}
