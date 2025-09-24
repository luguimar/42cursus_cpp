#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern cannot create form: " << formName << std::endl;
    return NULL;
}

