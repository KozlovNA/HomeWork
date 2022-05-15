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

    bool f{true};
    while (f)
    {
        f = false;
        for (auto it = lis.begin(); it != lis.end(); ++it)
        {
            auto at = it;
            ++at;
            if (*(it) > *(at))
            {
                int temp = *(at);
                *at = *it;
                *it = temp;
                f = true;
            }
        }

    }

    auto it = lis.begin();
    advance(it, n - m);
    for (; it != lis.end(); ++it)
        cout << *it << ' ';
}