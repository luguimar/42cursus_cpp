#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form contract("Contract", 40, 30);

        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        bob.signForm(contract);
        std::cout << contract << std::endl;

        Bureaucrat alice("Alice", 35);
        alice.signForm(contract);
        std::cout << contract << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
