#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    int n; std::cin >> n;
    auto m = new int [n];
    for(int i = 0; i < n; ++i)
        std::cin >> m[i];
    std::sort(m, m + n);
    int counter = 1;
    for(int i = 1; i < n; ++i)
        if(m[i] != m[i-1])
            ++counter;
    std::cout << counter;
}