#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &n, int s, int e)
    : name(n), isSigned(false), signGrade(s), execGrade(e) {
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &o)
    : name(o.name), isSigned(o.isSigned),
      signGrade(o.signGrade), execGrade(o.execGrade) {}

AForm &AForm::operator=(const AForm &o) {
    if (this != &o)
        this->isSigned = o.isSigned;
    return *this;
}

const std::string &AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << " (signGrade: " << f.getSignGrade()
        << ", execGrade: " << f.getExecGrade()
        << ", signed: " << f.getIsSigned() << ")";
    return out;
}
