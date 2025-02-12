#include "ClapTrap.hpp"

int main() {
    ClapTrap ct("CL4P-TP");

    ct.attack("Enemy");
    ct.takeDamage(3);
    ct.beRepaired(5);
    ct.takeDamage(12);
    ct.attack("Enemy");

    return 0;
}
