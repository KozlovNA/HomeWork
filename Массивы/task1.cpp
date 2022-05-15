#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum{0};
    int average;
    for(int i{0}; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    average = sum / n;

    unsigned count{0};
    vector<int> idx(n);
    for(int i{0}; i < n; ++i)
        idx[i] = -1;
    for(int i{0}; i < n; ++i)
        if (v[i] > average)
        {
            idx[count] = i;
            ++count;
        }

    cout << count << '\n';
    for(int i{0}; idx[i] != -1; ++i)
    {
        cout << idx[i] << ' ';
    }
}