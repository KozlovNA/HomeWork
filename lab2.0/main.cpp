#include <iostream>
int res = 50;
long long wuw(long long x, long long n){
    int res = 1;
    int i = 0;

    for (i = 0, res = 1; i < n; ++i){
        res *= x;
    }
    return res;
}

float wuw(float x, int n){
    float res = 1;
    int i = 0;

    for (i = 0, res = 1; i < n; ++i){
        res *= x;
    }
    return res;
}

int main() {
    for (int i = 0; i < 5; ++i)
    std::cout << wuw(3.99, i) << std::endl;
    return 0;
}
