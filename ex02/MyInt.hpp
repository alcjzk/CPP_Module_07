#pragma once

/// Integer type default initialized to 42 for testing purposes.
class MyInt
{
    public:
        ~MyInt() = default;
        MyInt();
        MyInt(const MyInt&) = default;
        MyInt(MyInt&&) = default;

        MyInt& operator=(const MyInt&) = default;
        MyInt& operator=(MyInt&&) = default;

        void    value(int value);
        int     value() const;

    private:
        int _value;
};
