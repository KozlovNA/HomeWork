#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    int max = 0, n_max = 0;
    for (int j = 0; j < m; ++j)
        max += arr[0][j];
    for (int j = 0; j < m; ++j)
    {
        int tmp = 0;
        for (int i = 0; i < n; ++i)
            tmp += arr[i][j];
        if (tmp > max)
        {
            max = tmp;
            n_max = j;
        }
    }
    cout << n_max;
}