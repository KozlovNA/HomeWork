#include <iostream>
using namespace std;

unsigned int sum_of_numbers(unsigned long long int n);

unsigned long long int factorial(unsigned int n) {
    long long int res;
    if (n == 1 || n == 0)
        return 1;
    res = n * factorial( n - 1);
    return res;
}

//----------------------------------------------------

unsigned int sum_of_numbers(unsigned long long int n)
{
    unsigned int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    unsigned int n;
    cin >>n;
    cout <<sum_of_numbers(factorial(n)) <<endl;
    return 0;
}
