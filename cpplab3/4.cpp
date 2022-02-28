#include <iostream>
using namespace std;
int main() {
    int a[100][100], a_t[100][100], m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a_t[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << endl;
        for (int j = 0; j < m; ++j)
            cout << a_t[i][j] << " ";
    }

    return 0;
}