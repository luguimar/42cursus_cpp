#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm(const std::string &target);
    ~PresidentialPardonForm();

    void executeAction() const;
};

#endif
