#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* wrong = someRandomIntern.makeForm("unknown form", "Target");
    if (!wrong)
        std::cout << "Form creation failed as expected." << std::endl;

    return 0;
}

