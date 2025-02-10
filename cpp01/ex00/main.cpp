#include "Zombie.hpp"

int main() {
    // Create a zombie on the heap
    Zombie* heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    // Create a zombie on the stack
    randomChump("StackZ");
    // Manually delete to see destructor message
    delete heapZombie;
    return 0;
}
