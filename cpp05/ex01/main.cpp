#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;

		alice.incrementGrade();			// becomes 1
		std::cout << alice << std::endl;

		alice.incrementGrade();			// boom
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bob("Bob", 151);		// constructor throws
	}
	catch (std::exception& e)
	{
		std::cerr << "Cannot create Bob: " << e.what() << std::endl;
	}
}

