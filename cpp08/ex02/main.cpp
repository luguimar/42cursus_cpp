#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void subjectLikeTest() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << "\n";
	mstack.pop();
	std::cout << mstack.size() << "\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(mstack); // cópia para std::stack
	std::cout << "stack copy size: " << s.size() << "\n";
}

static void constIterTest() {
	MutantStack<int> m;
	for (int i = 0; i < 10; ++i) m.push(i * i);
	MutantStack<int> const &cm = m;
	MutantStack<int>::const_reverse_iterator rit = cm.rbegin();
	for (; rit != cm.rend(); ++rit)
		std::cout << *rit << (rit + 1 == cm.rend() ? "\n" : " ");
}

static void withListContainer() {
	// Prova de template Container alternativo
	MutantStack<int, std::list<int> > ml;
	ml.push(1); ml.push(2); ml.push(3);
	for (MutantStack<int, std::list<int> >::iterator it = ml.begin(); it != ml.end(); ++it)
		std::cout << *it << (it == --ml.end() ? "\n" : " ");
}

int main() {
	subjectLikeTest();
	constIterTest();
	withListContainer();
	return 0;
}
