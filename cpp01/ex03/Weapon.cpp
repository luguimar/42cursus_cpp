#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

// Return a const reference to the weapon type
const std::string& Weapon::getType() const {
    return _type;
}

// Update the weapon type
void Weapon::setType(const std::string& newType) {
    _type = newType;
}
