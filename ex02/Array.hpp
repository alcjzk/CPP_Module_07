#pragma once

#include <cstddef>
#include <utility>
#include <cstring>
#include <exception>

template <typename T>
class Array
{
    public:
        ~Array();
        Array() = default;
        Array(unsigned int n);
        Array(const Array& other);
        Array(Array&& other) noexcept;

        Array&      operator=(const Array& other);
        Array&      operator=(Array&& other) noexcept;
        const T&    operator[](size_t index) const;
        T&          operator[](size_t index);

        size_t size() const;

    private:
        T*      _buffer = nullptr;
        size_t  _size = 0;

        static T* copy_buffer(const Array<T>& other);
};

template <typename T>
Array<T>::~Array()
{
    delete[] _buffer;
}

template <typename T>
Array<T>::Array(unsigned int n) : _buffer(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _buffer(copy_buffer(other)), _size(other._size)
{
}

template <typename T>
Array<T>::Array(Array<T>&& other) noexcept :
    _buffer(std::exchange(other._buffer, nullptr)), _size(std::exchange(other._size, 0))
{
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    T* buffer = copy_buffer(other);
    delete[] _buffer;
    _buffer = buffer;
    _size = other._size;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept
{
    _buffer = std::exchange(other._buffer, _buffer);
    _size = std::exchange(other._size, _size);
    return *this;
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return _buffer[index];
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
    {
        throw std::exception();
    }
    return _buffer[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
T* Array<T>::copy_buffer(const Array<T>& other)
{
    if (!other._buffer)
    {
        return nullptr;
    }
    return static_cast<T*>(std::memcpy(new T[other._size], other._buffer, other._size * sizeof(T)));
}
