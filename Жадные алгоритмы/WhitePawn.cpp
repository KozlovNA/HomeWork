#include <iostream>
#include <string>
using namespace std;

int main () {
    int **d = new int *[8];
    for (int i = 0; i < 8; ++i) {
        d[i] = new int[8];
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            d[i][j] = 0;
        }
    }

    int **a = new int *[8];
    for (int i = 0; i < 8; ++i) {
        a[i] = new int[8];
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            a[i][j] = 0;
        }
    }

    int pawn_count;
    cin >> pawn_count;

    string input;
    int y_coor, x_coor;
    char x_coor_c;
    for (int i = 0; i < pawn_count; i++) {
        cin >> input;
        x_coor = input[0] - 'a';
        y_coor = input[1] - '1';
        a[y_coor][x_coor] = 2;
    }
    cin >> input;
    x_coor = input[0] - 'a';
    y_coor = input[1] - '1';
    a[y_coor][x_coor] = 1;
    d[y_coor][x_coor] = 1;

    // сама динамика

    for (int i = y_coor + 1; i < 8; ++i) {
        for (int j = 0; j < 8; ++j){
            if (a[i][j] != 2 )
                d[i][j] += d[i-1][j];
            if (a[i][j] == 2)
                d[i][j] += d[i-1][j-1] + d[i-1][j+1];

        }
    }

    // вывод
/*
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n' << '\n';

    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
*/
    int sum = 0;
    for (int i = 0; i < 8; ++i){
        sum += d[7][i];
    }
    cout << sum;

return 0;
}