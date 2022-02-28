#include <iostream>
using namespace std;
int main() {
    int a[100][100], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int c = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = c;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << endl;
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
    }

    return 0;
}