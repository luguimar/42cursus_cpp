
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;
public:
    // Construtores
    Zombie(void);
    Zombie(std::string name);

    // Destrutor
    ~Zombie(void);

    // Função para o anúncio
    void announce(void) const;
};

#endif

