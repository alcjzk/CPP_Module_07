#pragma once

/// Integer type default initialized to 42 for testing purposes.
class MyInt
{
    public:
        ~MyInt() = default;
        MyInt() = default;
        MyInt(const MyInt&) = default;
        MyInt(MyInt&&) noexcept = default;

        MyInt& operator=(const MyInt&) = default;
        MyInt& operator=(MyInt&&) noexcept = default;

        void    value(int value);
        int     value() const;

    private:
        int _value = 42;
};
