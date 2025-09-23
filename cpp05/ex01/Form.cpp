#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Ctors / dtor -------------------------------------------------------------*/
Form::Form(const std::string& name, int gs, int ge)
	: _name(name), _signed(false), _gradeToSign(gs), _gradeToExec(ge)
{
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& rhs)
	: _name(rhs._name), _signed(rhs._signed),
	  _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec) {}
Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}
Form::~Form() {}

/* Getters ------------------------------------------------------------------*/
const std::string& Form::getName()		 const { return _name; }
bool				Form::isSigned()	 const { return _signed; }
int					Form::getGradeToSign() const { return _gradeToSign; }
int					Form::getGradeToExec() const { return _gradeToExec; }

/* Behaviour ----------------------------------------------------------------*/
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

/* Exceptions ---------------------------------------------------------------*/
const char* Form::GradeTooHighException::what() const throw()
{ return "form grade too high"; }
const char* Form::GradeTooLowException::what()  const throw()
{ return "form grade too low"; }

/* Operator<< ---------------------------------------------------------------*/
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form \"" << f.getName() << "\", "
	   << (f.isSigned() ? "signed" : "unsigned")
	   << " (sign: " << f.getGradeToSign()
	   << ", exec: " << f.getGradeToExec() << ")";
	return os;
}

