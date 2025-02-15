#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "[MateriaSource] Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    std::cout << "[MateriaSource] Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
    *this = src; // calls operator=
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    std::cout << "[MateriaSource] Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // Clean up existing
        for (int i = 0; i < 4; i++)
        {
            if (_templates[i])
            {
                delete _templates[i];
                _templates[i] = NULL;
            }
        }
        // Deep-copy
        for (int i = 0; i < 4; i++)
        {
            if (rhs._templates[i])
                _templates[i] = rhs._templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "[MateriaSource] Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i])
            delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    // The MateriaSource can learn up to 4 Materias.
    // We store them in the first available slot.
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m;
            return;
        }
    }
    // If we reach here, there's no free slot. The problem doesn't say we must delete m,
    // but typically we might just do nothing or manage it somehow.
    // We'll just ignore it to avoid leaking or misbehavior.
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    // If we find a known type, we clone it and return the new instance.
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    // Type not found.
    return 0;
}

