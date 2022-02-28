#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int max[1000] {0};
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        max[i] = arr[i];
    }
    cin >> m;

    bool f = true;
    while (f)
    {
        f = false;
        for (int j = 0; j < n-1; ++j)
            if (max[j] > max[j+1])
            {
                swap(max[j], max[j+1]);
                f = true;
            }
    }

    int mask[1000] {0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - m; j < n; ++j)
            if ( (arr[i] == max[j]) && (!mask[j]) )
            {
                mask[j] = 1;
                cout << arr[i] << ' ';
                break;
            }
    }
}