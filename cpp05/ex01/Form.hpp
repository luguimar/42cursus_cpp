#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;						// fwd

class Form
{
public:
	/* Orthodox Canonical Form */
	Form(const std::string& name, int gradeToSign, int gradeToExec);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	/* Getters */
	const std::string&	getName()		 const;
	bool				isSigned()		 const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	/* Behaviour */
	void	beSigned(const Bureaucrat& b);

	/* Exceptions */
	class GradeTooHighException : public std::exception
	{ public: const char* what() const throw(); };
	class GradeTooLowException  : public std::exception
	{ public: const char* what() const throw(); };

private:
	Form();									// disabled

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

