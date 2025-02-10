#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string _type;

public:
    Weapon(const std::string& type);
    ~Weapon();

    // Returns a const reference to the weapon type
    const std::string& getType() const;

    // Updates the weapon type
    void setType(const std::string& newType);
};

#endif
