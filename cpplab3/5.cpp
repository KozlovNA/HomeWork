#include <iostream>
using namespace std;
int main() {
    int m, n;
    char a[100][100], a_t[100][100], c;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cin.get(c);
            if (c != '\n') {
                a[i][j] = c;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a_t[i][j] = a[j][n - i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << endl;
        for (int j = 0; j < m; ++j)
            cout << a_t[i][j];
    }

    return 0;
}