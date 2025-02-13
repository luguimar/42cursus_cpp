#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _templates[i] = 0;
    // std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_templates[i]) {
                delete _templates[i];
                _templates[i] = 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_templates[i]) {
            delete _templates[i];
            _templates[i] = 0;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    // Store the Materia if there's an empty slot
    for (int i = 0; i < 4; i++) {
        if (_templates[i] == 0) {
            _templates[i] = m; // No clone here, or we can choose to clone
            // std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    // If full, do nothing (and possibly discard the Materia)
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    // For each known Materia, if the type matches, clone it
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    // If not found, return 0
    return 0;
}
