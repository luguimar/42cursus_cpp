#include "Span.hpp"

Span::Span(unsigned int N) : _data(), _cap(N) {}

Span::Span(Span const &other) : _data(other._data), _cap(other._cap) {}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		_data = other._data;
		_cap = other._cap;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
	if (_data.size() >= _cap)
		throw std::overflow_error("Span: capacidade excedida");
	_data.push_back(value);
}

unsigned int Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::logic_error("Span: não há elementos suficientes");
	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());
	long minDiff = LONG_MAX;
	for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i) {
		long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return static_cast<unsigned int>(minDiff);
}

unsigned int Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::logic_error("Span: não há elementos suficientes");

	std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

	long diff = static_cast<long>(*maxIt) - static_cast<long>(*minIt);
	return static_cast<unsigned int>(diff);
}
