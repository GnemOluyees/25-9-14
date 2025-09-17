#pragma once

constexpr int N = 1e5;

class bignum
{
public:
    void set_digit(int n);
    void add_digit();
    void init(int &n);
    void print();

    const int get_digit();

    bignum operator+(const bignum &other) const;
    bignum operator*(const bignum &other) const;

private:
    int digit = 0;
    int a[N] = {};
};
