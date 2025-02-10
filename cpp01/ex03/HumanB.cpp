#include "HumanB.hpp"
#include <iostream>

// HumanB might not start with a weapon, so we store a pointer
HumanB::HumanB(const std::string& name)
    : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    if (_weapon) {
        std::cout << _name
                  << " attacks with their "
                  << _weapon->getType()
                  << std::endl;
    } else {
        std::cout << _name
                  << " attacks with their bare fists (no weapon assigned!)"
                  << std::endl;
    }
}
