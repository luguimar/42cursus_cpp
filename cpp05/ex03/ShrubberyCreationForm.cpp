#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t)
    : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream out((target + "_shrubbery").c_str());
    if (out.is_open()) {
        out << "   *   " << std::endl;
        out << "  ***  " << std::endl;
        out << " ***** " << std::endl;
        out << "*******" << std::endl;
        out << "  |||  " << std::endl;
        out.close();
    }
}
