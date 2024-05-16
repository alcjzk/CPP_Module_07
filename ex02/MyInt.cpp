#include "MyInt.hpp"

void MyInt::value(int value)
{
    _value = value;
}

int MyInt::value() const
{
    return _value;
}
