#include <iostream>
#include <string>

int main() {
    // 1. A string variable
    std::string myString = "HI THIS IS BRAIN";

    // 2. Pointer to the string
    std::string* stringPTR = &myString;

    // 3. Reference to the string
    std::string& stringREF = myString;

    // --- Print memory addresses ---
    std::cout << "Memory address of myString:    " << &myString   << std::endl;
    std::cout << "Memory address held by PTR:    " << stringPTR   << std::endl;
    std::cout << "Memory address held by REF:    " << &stringREF  << std::endl;

    std::cout << std::endl;

    // --- Print string values ---
    std::cout << "Value of myString:            " << myString    << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR  << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF   << std::endl;

    return 0;
}
