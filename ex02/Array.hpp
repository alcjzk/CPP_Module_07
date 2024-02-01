#pragma once

#include <cstddef>

template <typename T>
class Array
{
    public:
        ~Array();
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array(Array&& other) noexcept;

        Array&  operator=(const Array& other);
        Array&  operator=(Array&& other) noexcept;
        T&      operator[](size_t index) const;

        size_t size() const;

    private:
        T*      _buffer;
        size_t  _size;

        static T* copy_buffer(const Array<T>& other);
};

#include "Array.tpp"
