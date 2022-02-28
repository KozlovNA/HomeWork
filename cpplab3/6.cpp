#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> m;

    bool f = true;
    while (f)
    {
        f = false;
        for (int j = 0; j < n-1; ++j)
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                f = true;
            }
    }

    for (int i = n-m; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
}