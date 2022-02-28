#include <iostream>
using namespace std;

struct something* calc_address(struct something* start, unsigned int number);

struct something {
    int a;
    bool b;
    char c;
};

int main() {
    something Arr[5];
    cout << Arr<< endl;
    cout << calc_address(Arr, 0) << endl << calc_address(Arr, 1) << endl << calc_address(Arr, 2);
    cout << endl << calc_address(Arr, 3) << endl << calc_address(Arr, 4);
    return 0;
}

struct something* calc_address(struct something* start, unsigned int number) {
    return start + number;
}