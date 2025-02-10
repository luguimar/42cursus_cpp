#include "Harl.hpp"

int main() {
    Harl harl;

    // Test each level
    std::cout << "===== DEBUG complaint =====" << std::endl;
    harl.complain("DEBUG");

    std::cout << "===== INFO complaint =====" << std::endl;
    harl.complain("INFO");

    std::cout << "===== WARNING complaint =====" << std::endl;
    harl.complain("WARNING");

    std::cout << "===== ERROR complaint =====" << std::endl;
    harl.complain("ERROR");

    std::cout << "===== Invalid complaint =====" << std::endl;
    harl.complain("NOT A VALID LEVEL");

    return 0;
}
