#include <cstdlib>
#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& value)
{
    std::cout << value << '\n';
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    float float_array[] = {0.1f, 0.2f, 0.3f};

    iter(array, sizeof(array) / sizeof(*array), print);
    iter(float_array, sizeof(float_array) / sizeof(*float_array), print);
    return EXIT_SUCCESS;
}
