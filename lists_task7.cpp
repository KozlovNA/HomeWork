#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> lis;
    int n, m, input;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        lis.push_back(input);
    }
    cin >> m;

    lis.reverse();
    while(lis.size() > m)
        lis.erase(min_element(lis.begin(), lis.end()));
    lis.reverse();

    for(auto i : lis)
        cout << i << ' ';
}