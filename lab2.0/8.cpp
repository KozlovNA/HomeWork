#include <iostream>
using namespace std;

unsigned int sum_of_numbers(unsigned long long int n);
unsigned long long int nonacci(unsigned int n);

//----------------------------------------------------

unsigned long long int nonacci(unsigned int n) {
    if (n < 8) {
        return 0;
    } else if (n == 8 || n == 9) {
        return 1;
    } else {
        unsigned long long int res = 0;
        for (int i = 1; i <= 9; ++i){
            res += nonacci(n-i);
        }
        return res;
    }
}

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
    cout <<sum_of_numbers(nonacci(n)) <<endl;
    return 0;
}
