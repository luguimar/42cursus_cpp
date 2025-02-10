#include "Harl.hpp"
#include <iostream>

// Constructor / Destructor (if you need them)
Harl::Harl() {}
Harl::~Harl() {}

// Private member functions
void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for "
              << "my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
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
              << "I’ve been coming for years whereas you started working "
              << "here since last month." << std::endl << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl << std::endl;
}

// Public complain method
void Harl::complain(std::string level) {

    // 1) Define an array of function pointers
    //    Each pointer matches the signature: void (Harl::*)()
    typedef void (Harl::*HarlMemFn)();
    HarlMemFn funcs[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // 2) Define an array of levels corresponding to these functions
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // 3) Loop through all possible levels and call the correct function if matched
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*funcs[i])(); // Call the member function pointer on 'this'
            return;             // Return after the first match
        }
    }

    // If we get here, no valid level was found
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
}
