#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! If you did, "
              << "I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming here for years whereas you started working "
              << "here since last month." << std::endl << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl << std::endl;
}

/*
    complain(std::string level):
    This method does NOT just print a single level. Instead, we figure out
    the "index" of the given level in [DEBUG, INFO, WARNING, ERROR] and
    then print from that level upward using a switch (with fall-through).
*/
void Harl::complain(std::string level) {
    int levelIndex = -1;

    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // Determine the index based on the given 'level'
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

    // Use a switch statement to decide how much to print
    switch (levelIndex) {
        case 0:
            this->debug();
            // fall through
        case 1:
            this->info();
            // fall through
        case 2:
            this->warning();
            // fall through
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
            break;
    }
}
