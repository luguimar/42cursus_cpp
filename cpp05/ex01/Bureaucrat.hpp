#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
public:
	/* Orthodox Canonical Form */
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	/* Getters                                                    */
	const std::string&	getName()  const;
	int					getGrade() const;

	/* Grade manipulation                                         */
	void	incrementGrade();		// grade -- (1 is highest)
	void	decrementGrade();		// grade ++ (150 is lowest)
    void signForm(Form& f) const;
	/* Exceptions                                                 */
	class GradeTooHighException : public std::exception
	{
		public: const char* what() const throw();	// C-style “noexcept”
	};
	class GradeTooLowException : public std::exception
	{
		public: const char* what() const throw();
	};

private:
	Bureaucrat();						// not implemented
	const std::string	_name;
	int					_grade;			// 1 … 150
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif

