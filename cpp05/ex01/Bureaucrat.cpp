#include "Bureaucrat.hpp"

/* ------------------------------------------------------------------------- */
/*  Orthodox Canonical Form                                                  */
/* ------------------------------------------------------------------------- */
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;			// _name is const
	return *this;
}
Bureaucrat::~Bureaucrat() {}

/* ------------------------------------------------------------------------- */
/*  Getters & manipulators                                                   */
/* ------------------------------------------------------------------------- */
const std::string& Bureaucrat::getName() const { return _name; }
int  Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

/* ------------------------------------------------------------------------- */
/*  Exceptions                                                               */
/* ------------------------------------------------------------------------- */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return "grade is too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return "grade is too low"; }

/* ------------------------------------------------------------------------- */
/*  Non-member                                                               */
/* ------------------------------------------------------------------------- */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}

void Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn’t sign "
				  << f.getName() << " because " << e.what() << std::endl;
	}
}
