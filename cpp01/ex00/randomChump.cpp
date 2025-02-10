#include "Zombie.hpp"

// Creates a zombie on the stack, immediately announces it
void randomChump(std::string name) {
    Zombie z(name);
    z.announce();
}
