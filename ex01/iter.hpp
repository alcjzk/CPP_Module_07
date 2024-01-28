#pragma once

#include <cstddef>

template <typename T>
void iter(T* array, size_t length, void (*func)(const T&))
{
    for (size_t index = 0; index < length; index++)
    {
        func(array[index]);
    }
}
