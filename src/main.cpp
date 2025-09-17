#include <iostream>
#include <cstring>

#include <opetators.hpp>

char d;
bignum a, b, results;
std::string equation;

void cin_equation();

int main()
{
    std::cout << "Please enter the equation. Example:123+345\n";

    // Please enter the equation.
    // Example:123=345

    cin_equation();

    switch (d)
    {
    case '+':
        results = a + b;
        break;

    case '*':
        results = a * b;
        break;

    case '-':
        results = a + b;
        break;

    case '/':

        results = a + b;
        break;

    default:
        break;
    }

    results.print();

    return 0;
}

void cin_equation()
{
    std::cin >> equation;

    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '+' || equation[i] == '-' ||
            equation[i] == '*' || equation[i] == '/')
        {
            d = equation[i];
            break;
        }

        int n = equation[i] - '0';

        a.init(n);
    }

    // 此处应注意，不要不小心访问 string 的末位或者越界
    // for(int i = 0; i <= equation.length() - 1 ; i++ )
    //                         attention:    - 1
    // or you can add this:
    // if(equation[i] != ' \0 ')

    for (int i = a.get_digit() + 1; i < equation.length(); i++)
    {
        int n = equation[i] - '0';
        b.init(n);
    }
}