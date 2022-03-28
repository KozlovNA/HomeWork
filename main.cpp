#include <iostream>
#include <cmath>
using namespace std;


float sum1(float const psi[], float const pdf[], float const dv, unsigned size) {
    if (size == 1)
        return *psi * *pdf * dv;
    unsigned left_size, right_size;
    left_size = size/2;
    right_size = size - size/2;
    float left_sum = sum1(psi, pdf, dv, left_size);
    float right_sum = sum1(psi + left_size, pdf + left_size, dv, right_size);

    return left_sum + right_sum;
}
float sum2(float const psi[], float const pdf[], float const dv, unsigned size) {
    int step = 1;
    float prod[size];
    for (int i{0}; i < size; i++) {
        prod[i] = psi[i] * pdf[i];
    }
    while (step <= size/2) {
        for (int i{0}; i < size - step + 1; i+=step){
            prod[i] += prod[i + step];
        }
        step*=2;
    }
    return prod[0]*dv;
}

float sum3(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0.f;
    float y = 0.f;
    float c = 0.f;
    float t = 0.f;
    float prod[size];
    for (int i{0}; i < size; i++) {
        prod[i] = psi[i] * pdf[i];
    }
    for (int i{0}; i < size; i++) {
        y = prod[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum*dv;
}

float sum4(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum{0};
    for (int i{0}; i < size; i++) {
        sum = fma(psi[i], pdf[i], sum);
    }
    return sum*dv;
}
 float* maxwell(float* pdf, int n, float const dv) {
    float const f_pi = 3.14159265359f;
    float const T = 273.f;
    for (int i{0}; i < n; ++i) {
        pdf[i] = powf(T*f_pi, -0.5)*exp(-((i - n/2)*dv)*((i - n/2)*dv)/T);
    }
    return pdf;
}

float* psi_func(float* psi, int n, float const dv) {
    for (int i{0}; i < n; ++i) {
        psi[i] = abs(((i - n)/2)*dv);
    }
    return psi;
}

int main() {
    float const f_pi = 3.14159265359f;
    double const d_pi = 3.14159265359;
    float const f_e = 2.718281828459f;
    double const d_e = 2.718281828459;
    float const dv = 0.01;
    int const n = 100000;
    float const nf = 100000.f;
    float pdf[n], psi[n];

    maxwell(pdf, n, dv);
    psi_func(psi, n, dv);
    cout << sum1(psi, pdf, dv, n) << endl;
    cout << sum2(psi, pdf, dv, n) << endl;
    cout << sum3(psi, pdf, dv, n) << endl;
    cout << sum4(psi, pdf, dv, n) << endl;


    return 0;
}
