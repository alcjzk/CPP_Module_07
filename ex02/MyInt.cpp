#include "MyInt.hpp"

MyInt::MyInt() : _value(42)
{
}

void MyInt::value(int value)
{
    _value = value;
}

int MyInt::value() const
{
    return _value;
}
