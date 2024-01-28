#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include "util.hpp"

int main()
{
    // Subject tests
    {
        int a = 2;
        int b = 3;

        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << '\n';
        std::cout << "min(a, b) = " << ::min(a, b) << '\n';
        std::cout << "max(a, b) = " << ::max(a, b) << '\n';

        std::string c = "chaine1";
        std::string d = "chaine2";

        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << '\n';
        std::cout << "min(c, d) = " << ::min(c, d) << '\n';
        std::cout << "max(c, d) = " << ::max(c, d) << '\n';
    }

    int a = 42;
    int b = 42;

    // Assert min/max return 2nd argument when equal
    assert(&::max(a, b) == &b);
    assert(&::min(a, b) == &b);

    return EXIT_SUCCESS;
}
