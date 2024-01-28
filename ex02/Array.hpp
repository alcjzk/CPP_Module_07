#pragma once

#include <cstring>
#include <utility>
#include <exception>

template <typename T>
class Array
{
    public:
        ~Array()
        {
            if (_buffer)
            {
                delete[] _buffer;
            }
        }

        Array() : _size(0), _buffer(nullptr) {}

        Array(unsigned int n) : _size(n), _buffer(new[n] T()) {}

        Array(const Array& other) :
            _size(other._size),
            _buffer(std::memcpy(new[other._size] T(), other._buffer, other._size)) {}

        Array(Array&& other) noexcept :
            _size(std::exchange(other._size, 0)),
            _buffer(std::exchange(other._buffer, nullptr)) {}

        Array& operator=(const Array& other)
        {
            if (*this == other)
            {
                return *this;
            }
            if (_buffer)
            {
                delete[] _buffer;
                _buffer = nullptr;
            }
            _buffer = new[other._size] T();
            _size = other._size;
            std::memcpy(_buffer, other._buffer, _size);
            return *this;
        }

        Array& operator=(Array&& other) noexcept
        {
            _size = std::exchange(other._size, _size);
            _buffer = std::exchange(other._buffer, _buffer);
            return *this;
        }

        T& operator[](size_t index)
        {
            if (index >= _size)
            {
                throw std::exception;
            }
            return _buffer[index];
        }

    private:
        size_t  _size;
        T*      _buffer;
};
