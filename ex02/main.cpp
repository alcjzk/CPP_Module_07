#include <cstdlib>
#include <iostream>
#include <cassert>
#include "Array.hpp"
#include "MyInt.hpp"

/// Returns true if `array1` is a deepcopy of `array2`, false otherwise. Arrays must have at least
/// a size of 2.
bool array_is_deepcopy(Array<int>& array1, Array<int>& array2)
{
    if (array1.size() != array2.size())
        return false;

    for (size_t index = 0; index < array1.size(); index++)
    {
        if (array1[index] != array2[index])
            return false;
    }

    array1[0] += 1;
    if (array1[0] == array2[0])
        return false;
    array1[0] -= 1;

    array2[1] += 1;
    if (array1[1] == array2[1])
        return false;
    array2[1] -= 1;

    return true;
}

int main()
{
    {
        Array<int> empty;

        try
        {
            (void)empty[0];
            assert(false);
        } catch (...) {}
        return EXIT_SUCCESS;
    }

    {
        // Construction with n creates an array of n default initialized elements (MyInt is 42 by
        // default).
        unsigned int n = 3;
        Array<MyInt> array(n);
        assert(array.size() == n);
        for (size_t index = 0; index < array.size(); index++)
        {
            assert(array[index].value() == 42);
        }
    }

    {
        Array<int> array(3);
        for (size_t index = 0; index < array.size(); index++)
        {
            array[index] = 9;
        }

        Array<int> array_copy_constructed(array);
        Array<int> array_copy_assigned = array;

        assert(array_is_deepcopy(array_copy_constructed, array));
        assert(array_is_deepcopy(array_copy_assigned, array));
    }
}
