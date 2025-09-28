#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector() {
	std::vector<int> v;
	for (int i = 0; i < 10; ++i) v.push_back(i * 2); // 0,2,4,...,18
	try {
		std::vector<int>::iterator it = easyfind(v, 8);
		std::cout << "vector: encontrado " << *it << "\n";
		*it = 81; // prova que o iterador não-const funciona
		std::cout << "vector: substituido por " << v[4] << "\n";
	} catch (std::exception const &e) {
		std::cout << e.what() << "\n";
	}
	try {
		(void)easyfind(v, 7);
	} catch (std::exception const &e) {
		std::cout << "vector: esperado erro -> " << e.what() << "\n";
	}
}

static void testListConst() {
	std::list<int> l;
	for (int i = 3; i <= 15; i += 3) l.push_back(i); // 3,6,9,12,15
	try {
		std::list<int> const &cl = l;
		std::list<int>::const_iterator it = easyfind(cl, 12);
		std::cout << "list<const>: encontrado " << *it << "\n";
	} catch (std::exception const &e) {
		std::cout << e.what() << "\n";
	}
}

static void testDeque() {
	std::deque<int> d;
	d.push_back(42);
	d.push_back(-1);
	d.push_back(7);
	try {
		std::deque<int>::iterator it = easyfind(d, -1);
		std::cout << "deque: encontrado " << *it << "\n";
	} catch (std::exception const &e) {
		std::cout << e.what() << "\n";
	}
}

int main() {
	testVector();
	testListConst();
	testDeque();
	return 0;
}
