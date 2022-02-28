#include <iostream>
using namespace std;
int main() {
    int a[10000], n, sum = 0, avg;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    avg = sum / n;
    for (int i = 0; i < n; ++i) {
        if (a[i] > avg) {
            cout << a[i] << " ";
        }
    }
    return 0;
}