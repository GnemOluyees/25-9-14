#include <opetators.hpp>
#include <iostream>

const int bignum::get_digit()
{
    return bignum::digit;
}

void bignum::init(int &n)
{
    bignum::digit++;
    a[digit] = n;
}

void bignum::print()
{
    for (int i = 1; i <= bignum::digit; i++)
        std::cout << a[i];
    std::cout << "\n";
}

void bignum::set_digit(int n)
{
    bignum::digit = n;
}

void bignum::add_digit()
{
    bignum::digit++;
}

bignum bignum::operator*(const bignum &other) const
{
    bignum c;
    c.set_digit(this->digit);

    // 规定：this乘数，other被乘数（下面）

    int this_src = this->digit, other_src = other.digit, c_src = c.digit;

    for (int i = other_src; i >= 1; i--)
    {
        c_src = c.digit;

        for (int j = this_src; j >= 1; j--)
        {
            c.a[c_src - (other_src - i)] += other.a[i] * this->a[j];
            c_src--;
        }
        for (int j = c.digit; j >= 1; j--)
        {
            c.a[j - 1] += c.a[j] / 10;
            c.a[j] %= 10;
        }
        if (c.a[0] != 0)
        {
            c.add_digit();

            for (int j = c.digit; j >= 1; j--)
                c.a[j] = c.a[j - 1];

            c.a[0] = 0;
        }
    }
    return c;
}

bignum bignum::operator+(const bignum &other) const
{
    bignum c;
    c.set_digit(std::max(this->digit, other.digit));

    int this_src = this->digit, other_src = other.digit, c_src = c.digit;

    for (int i = std::max(this->digit, other.digit); i >= 1; i--)
    {
        c.a[c_src] = this->a[this_src] + other.a[other_src];
        c_src--;
        this_src--;
        other_src--;

        if (other_src == -1)
            other_src = 0;
    }

    for (int i = c.digit; i >= 1; i--)
    {
        c.a[i - 1] += c.a[i] / 10;
        c.a[i] %= 10;
    }

    if (c.a[0] != 0)
    {
        c.add_digit();

        for (int i = c.digit; i >= 1; i--)
            c.a[i] = c.a[i - 1];
        c.a[0] = 0;
    }

    return c;
}