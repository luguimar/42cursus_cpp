#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::out_of_range
#include <cstddef>   // size_t

template <typename T>
class Array {
public:
    // Orthodox Canonical Form
    Array();
    explicit Array(unsigned int n);
    Array(Array const &other);
    Array & operator=(Array const &other);
    ~Array();

    // Element access with bounds checking
    T & operator[](unsigned int index);
    T const & operator[](unsigned int index) const;

    // Observers
    unsigned int size() const;

private:
    T*            _data;
    unsigned int  _size;
};

// Template implementation
#include "Array.tpp"

#endif // ARRAY_HPP
