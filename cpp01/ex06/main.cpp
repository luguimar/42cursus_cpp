#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <LOG_LEVEL>" << std::endl;
        std::cerr << "       Possible levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    Harl harl;
    harl.complain(level);

    return 0;
}
