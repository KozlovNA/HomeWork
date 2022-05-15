#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> m;
    int n; int input;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        m.push_back(input);
    }
    for (auto it = --m.end(); it != --m.begin(); --it)
        cout << *it << ' ';
}
