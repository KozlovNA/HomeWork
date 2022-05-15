#include <iostream>
#include <cmath>
#include <numbers>

using namespace std;

float mean(float const psi[], float const pdf[], float const dv, unsigned size)
{
    float sum{0.f};
    for (unsigned i{0}; i < size; ++i)
    {
        sum += psi[i] * pdf[i];
    }
    return dv * sum;
}

float recursive(float const psi[], float const pdf[], float const dv, unsigned size)
{
    if(size == 1)
        return psi[0] * pdf[0] * dv;
    else
    {
        unsigned middle = size / 2;
        return recursive(psi, pdf, dv, middle) + recursive(psi + middle, pdf + middle, dv, size - middle);
    }
}

float close(float const psi[], float const pdf[], float const dv, unsigned size)
{
    auto* funk = new float [size];
    for(int i{0}; i < size; ++i)
        funk[i] = psi[i] * pdf[i];

    for(int i{2}; i < 2 * size; i *= 2)
        for(int j{0}; j + i / 2 < size; j += i)
            funk[j] += funk[j + i / 2];

    float sum{funk[0]};
    delete[] funk;
    return sum * dv;
}

float kahan_sum(float const psi[], float const pdf[], float const dv, unsigned size)
{
    auto* funk = new float [size];
    for(int i{0}; i < size; ++i)
        funk[i] = psi[i] * pdf[i];

    float sum{0.f}; float reminder{0.f};
    float main;  float tmp;
    for(int i{0}; i < size; ++i)
    {
        main = funk[i] - reminder;
        tmp = sum + main;
        reminder = (tmp - sum) - main;
        sum = tmp;
    }
    delete[] funk;
    return sum * dv;
}

float fma(float const psi[], float const pdf[], float const dv, unsigned size)
{
    float sum{0.f};
    for (int i{0}; i < size; ++i)
        sum = fma(psi[i], pdf[i], sum);
    return sum * dv;
}

double precise(float const psi[], float const pdf[], float const dv, unsigned size)
{
    auto* funk = new double [size];
    for(int i{0}; i < size; ++i)
        funk[i] = psi[i] * pdf[i];

    double sum{0.f}; double reminder{0.f};
    double main;  double tmp;
    for(int i{0}; i < size; ++i)
    {
        main = funk[i] - reminder;
        tmp = sum + main;
        reminder = (tmp - sum) - main;
        sum = tmp;
    }
    delete[] funk;
    return sum * dv;
}

int main()
{
    unsigned size = 100000000;
    float T{10};
    float dv{1e-4}; float zero_val{powf(std::numbers::pi * T, -0.5)};
    auto* pdf = new float [size]; auto* psi = new float [size];
    bool f{true}; float val{zero_val};
    int i{0};
    for(; val > zero_val / 1000; ++i)
    {
        val = powf(std::numbers::pi * T, -0.5) * exp(- (i * dv) * (i * dv) / T);
        pdf[size / 2 + i] = val;
        pdf[size / 2 - i] = val;
    }
    for(int j = - i; j < i; ++j)
    {
        psi[size / 2 + j] = std::abs(j * dv);   
    }

    unsigned new_size = 2 * abs(i) + 1;

    std::cout << mean(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
    std::cout << recursive(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
    std::cout << close(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
    std::cout << kahan_sum(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
    std::cout << fma(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
    std::cout.precision(12);
    std::cout << precise(psi + size/2 - i, pdf + size/2 - i, dv, new_size) << '\n';
}