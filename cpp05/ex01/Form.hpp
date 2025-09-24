#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

