#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "===== Intern Tests =====" << std::endl;

    Intern someRandomIntern;

    AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
    AForm *form4 = someRandomIntern.makeForm("invalid form", "Nobody"); // should fail

    std::cout << "\n===== Bureaucrat Tests =====" << std::endl;

    Bureaucrat boss("Boss", 1);
    Bureaucrat peasant("Peasant", 150);

    std::cout << boss << std::endl;
    std::cout << peasant << std::endl;

    std::cout << "\n===== Signing and Executing Forms =====" << std::endl;

    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
    }

    if (form2) {
        boss.signForm(*form2);
        boss.executeForm(*form2);
    }

    if (form3) {
        peasant.signForm(*form3);   // should fail: grade too low
        boss.signForm(*form3);      // succeeds
        boss.executeForm(*form3);   // executes pardon
    }

    // Clean up (avoid leaks!)
    delete form1;
    delete form2;
    delete form3;
    delete form4; // nullptr, safe to delete

    return 0;
}

