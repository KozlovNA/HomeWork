#include <iostream>
using namespace std;

bool is_simple(int n){
    int c = 0;
    for (int i = 1; i <= n; ++i){
        if (n%i == 0) {
            c++;
        }
    }
    if (c == 2){
        return true;
    } else {
        return false;
    }
}

int main ( ) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        if ( is_simple(i) )
            cout <<i <<' ';
    cout <<endl;
    return 0;
}

