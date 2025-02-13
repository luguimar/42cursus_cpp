#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string _type;

public:
    // Constructors & Destructor
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    // Getters
    std::string const & getType() const; //Returns the materia type

    // Pure virtual clone()
    virtual AMateria* clone() const = 0;

    // Virtual use method
    virtual void use(ICharacter& target);
};

#endif
