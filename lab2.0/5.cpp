#include <iostream>
using namespace std;

void binary(unsigned int n)
{
    unsigned int bin = 0;
    for (int pow = 1; n > 0; bin += (n%2)*pow, n /= 2, pow *= 10);
    cout << bin << '\n';
}

int main()
{
    unsigned int n;
    cin >>n;
    binary(n);
    cout <<endl;
    return 0;
}
