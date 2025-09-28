// Implementation separated to keep template definitions visible to translation units.

#include <new> // not strictly needed, but explicit
#include <algorithm> // NOT used here; included by default headers though (we won't use any algo)

template <typename T>
Array<T>::Array() : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n) {
    if (_size == 0) {
        _data = 0;
    } else {
        // Value-initialize elements (calls default ctor for class types).
        _data = new T[_size]();
    }
}

template <typename T>
Array<T>::Array(Array const &other) : _data(0), _size(other._size) {
    if (_size == 0) {
        _data = 0;
    } else {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

template <typename T>
Array<T> & Array<T>::operator=(Array const &other) {
    if (this != &other) {
        // Allocate new buffer first to provide strong exception safety.
        T *newData = 0;
        if (other._size != 0) {
            newData = new T[other._size];
            for (unsigned int i = 0; i < other._size; ++i)
                newData[i] = other._data[i];
        }
        delete [] _data;
        _data = newData;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete [] _data;
}

template <typename T>
T & Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Array: index out of bounds");
    return _data[index];
}

template <typename T>
T const & Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Array: index out of bounds");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}