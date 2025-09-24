#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade(); // vai lançar exceção
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat jim("Jim", 149);
        std::cout << jim << std::endl;

        jim.decrementGrade();
        std::cout << jim << std::endl;

        jim.decrementGrade(); // vai lançar exceção
        std::cout << jim << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat wrong("Wrong", 200); // construtor inválido
    }
    catch (std::exception& e) {
        std::cerr << "Constructor exception: " << e.what() << std::endl;
    }

    return 0;
}

