#include "Zombie.hpp"

int main() {
    int numberOfZombies = 5;
    std::string hordeName = "HordeZombie";

    // Create a horde of 5 zombies named "HordeZombie"
    Zombie* horde = zombieHorde(numberOfZombies, hordeName);

    if (horde == NULL) {
        std::cout << "Invalid number of zombies" << std::endl;
        return 1;
    }

    // Each zombie announces itself
    for (int i = 0; i < numberOfZombies; i++) {
        horde[i].announce();
    }

    // Clean up the entire horde to avoid memory leaks
    delete[] horde;

    return 0;
}
