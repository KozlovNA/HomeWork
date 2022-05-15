#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> m;
    int n; int input;
    double mean = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        mean += input;
        m.push_back(input);
    }
    for (auto i : m)
        if (n * i > mean)
            cout << i << ' ';
}
