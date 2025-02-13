#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name) {
    // Initialize inventory to NULL
    for (int i = 0; i < 4; i++) {
        _inventory[i] = 0;
    }
    // std::cout << "Character constructor called for " << _name << std::endl;
}

Character::Character(const Character &other) {
    // std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

Character &Character::operator=(const Character &other) {
    // std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        // First, delete any existing Materias
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = 0;
            }
        }
        // Then copy Materias from 'other'
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character() {
    // std::cout << "Character destructor called for " << _name << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = 0;
        }
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == 0) {
            _inventory[i] = m;
            // std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    // Inventory full -> do nothing
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return;
    // The instruction says: DO NOT delete the Materia
    // just set the slot to null
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}
