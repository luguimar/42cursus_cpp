#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

static void basicDemo() {
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest: " << sp.shortestSpan() << "\n";
	std::cout << "longest : " << sp.longestSpan() << "\n";
}

static void massDemo(unsigned int n) {
	Span sp(n);
	std::vector<int> bulk;
	bulk.reserve(n);
	std::srand(1337);
	for (unsigned int i = 0; i < n; ++i)
		bulk.push_back(std::rand());
	sp.addNumbers(bulk.begin(), bulk.end());
	std::cout << "N=" << sp.size()
	          << " shortest=" << sp.shortestSpan()
	          << " longest="  << sp.longestSpan() << "\n";
}

static void errorDemo() {
	try {
		Span sp(1);
		sp.addNumber(10);
		sp.shortestSpan();
	} catch (std::exception const &e) {
		std::cout << "erro esperado: " << e.what() << "\n";
	}
	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	} catch (std::exception const &e) {
		std::cout << "erro esperado: " << e.what() << "\n";
	}
}

int main() {
	basicDemo();
	massDemo(10000);
	errorDemo();
	return 0;
}
