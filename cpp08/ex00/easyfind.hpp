#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: valor não encontrado");
	return it;
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: valor não encontrado");
	return it;
}

#endif // EASYFIND_HPP
