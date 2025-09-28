#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// If equal, return the second parameter.
template <typename T>
T const & min(T const & a, T const & b) {
    return (b <= a) ? b : a;
}

// If equal, return the second parameter.
template <typename T>
T const & max(T const & a, T const & b) {
    return (b >= a) ? b : a;
}

#endif // TEMPLATES_HPP
