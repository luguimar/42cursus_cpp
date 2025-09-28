#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

// Non-const overload: allows applying functions that modify elements.
template <typename T, typename F>
void iter(T *array, std::size_t length, F func) {
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

// Const overload: allows applying functions that take const references.
template <typename T, typename F>
void iter(T const *array, std::size_t length, F func) {
    if (!array)
        return;
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif // ITER_HPP