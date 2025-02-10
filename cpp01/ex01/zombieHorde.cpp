#include "Zombie.hpp"

// Creates an array of N zombies and sets their name
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }
    // Allocate N Zombies in one single allocation
    Zombie* horde = new Zombie[N];
    // Set the name for each zombie in the horde
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}
