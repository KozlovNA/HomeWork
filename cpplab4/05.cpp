#include <iostream>
using namespace std;

int* copyarr(int* a, unsigned int size);

int main() {
    int A[4] = {1, 2, 3, 4};
    int* c = copyarr(A, 4);
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); ++i) {
        cout << *(c + i) << " ";
    }
    return 0;
}

int* copyarr(int* a, unsigned int size) {
    int* Copy = new int(size);
    for (int i = 0; i < size; ++i) {
        *(Copy + i) = *(a + i);
    }
    return Copy;
}