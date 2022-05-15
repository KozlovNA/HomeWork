#include <iostream>
#include <cmath>
using namespace std;

int len(int* A, int k, int* Memory){
    if(k == 1){
        return abs(A[1] - A[0]);
    }
    if(k < 1){
        return 0;
    }
    if(Memory[k] != -1){
        return Memory[k];
    }
    Memory[k] = min(abs(A[k] - A[k-1]) + len(A, k-1, Memory), 3*abs((A[k] - A[k-2])) + len(A, k-2, Memory));
    return Memory[k];
}


int main()
{
    int N;
    cin >>N;
    int* A = new int[N];
    int* Memory = new int[N];
    for(int i = 0; i < N; i++){
        cin >>A[i];
        Memory[i] = -1;
    }
    cout << len(A, N-1, Memory);
    return 0;
}