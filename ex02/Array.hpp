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

        Array() : _buffer(nullptr), _size(0) {}

        Array(unsigned int n) :_buffer(new T[n]), _size(n) {}

        Array(const Array& other) :
            _buffer(copy_buffer(other)),
            _size(other._size) {}

        Array(Array&& other) noexcept :
            _buffer(std::exchange(other._buffer, nullptr)),
            _size(std::exchange(other._size, 0)) {}

        Array& operator=(const Array& other)
        {
            T* buffer;

            if (*this == other)
            {
                return *this;
            }

            buffer = copy_buffer(other);
            if (_buffer)
            {
                delete[] _buffer;
            }

            _buffer = buffer;
            _size = other._size;
            return *this;
        }

        Array& operator=(Array&& other) noexcept
        {
            _buffer = std::exchange(other._buffer, _buffer);
            _size = std::exchange(other._size, _size);
            return *this;
        }

        T& operator[](size_t index) const
        {
            if (index >= _size)
            {
                throw std::exception();
            }
            return _buffer[index];
        }

        size_t size() { return _size; }

    private:
        T*      _buffer;
        size_t  _size;

        static T* copy_buffer(Array<T> other)
        {
            if (!other._buffer)
            {
                return nullptr;
            }
            return static_cast<T*>(std::memcpy(new T[other._size], other._buffer, other._size));
        }
};
