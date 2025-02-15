#include "Character.hpp"
#include <iostream>

Character::Character()
    : _name("default")
{
    std::cout << "[Character] Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const & name)
    : _name(name)
{
    std::cout << "[Character] Parameter constructor called for " << name << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const & src)
{
    std::cout << "[Character] Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    *this = src; // calls operator=
}

Character & Character::operator=(Character const & rhs)
{
    std::cout << "[Character] Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // 1) Copy the name
        _name = rhs._name;
        
        // 2) Clean up any existing inventory
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        // 3) Deep-copy the Materias
        for (int i = 0; i < 4; i++)
        {
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "[Character] Destructor called for " << _name << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            // We put the Materia in the first free slot, then stop.
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    // The subject requires NOT to delete here.
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}

