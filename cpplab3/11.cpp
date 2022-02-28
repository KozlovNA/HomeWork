#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = 0; j < n - 1; ++j)
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
    }

    int separ = 0;
    for(; separ < n && arr[separ] < 0; ++separ);
    for (int i = separ; i < n; ++i)
        if (i == 0 || arr[i] != arr[i-1])
            cout << arr[i] << ' ';
    for (int i = separ-1; i >= 0; --i)
        if (i == 0 || arr[i] != arr[i+1])
            cout << arr[i] << ' ';
}