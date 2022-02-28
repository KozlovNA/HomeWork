#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = (20 + log(n) / log(2)) / 8;
    double double_t =  (20 + log(n) / log(2)) / 8;
    if (t >= double_t) {
        cout << t;
    } else {
        cout << t + 1;
    }
    return 0;
}