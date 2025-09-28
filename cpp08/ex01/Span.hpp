#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span {
public:
	explicit Span(unsigned int N);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span();

	void addNumber(int value);

	template <typename InputIt>
	void addNumbers(InputIt first, InputIt last) {
		unsigned int count = 0;
		for (InputIt it = first; it != last; ++it) ++count;
		if (count > _cap - _data.size())
			throw std::overflow_error("Span: capacidade excedida na inserção por intervalo");
		_data.insert(_data.end(), first, last);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	unsigned int capacity() const { return _cap; }
	unsigned int size() const { return static_cast<unsigned int>(_data.size()); }

private:
	std::vector<int> _data;
	unsigned int _cap;
};

#endif // SPAN_HPP
