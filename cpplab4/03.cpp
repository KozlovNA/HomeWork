#include <iostream>
using namespace std;

bool do_some_work(int *a, int *b) {
    return (*a - *b > 0);
}

int main() {
    int a, b;
    cin >> a >> b;
    if (do_some_work(&a, &b)) {
        cout << a - b;
    } else {
        cout << a + b;
    }
    return 0;
}