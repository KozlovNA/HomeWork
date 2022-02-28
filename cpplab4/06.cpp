#include <iostream>
using namespace std;

int** transpose(int** matrix, unsigned int N, unsigned int M)
{
    int** transmat = new int* [M];
    for (int i = 0; i < M; ++i)
        transmat[i] = new int [N];

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            transmat[i][j] = matrix[j][i];

    return transmat;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int** matrix = new int* [N];
    for (int i = 0; i < N; ++i)
        matrix[i] = new int [M];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrix[i][j];

    int** transmat;
    transmat = transpose(matrix, N, M);
    cout << endl;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << transmat[i][j] << ' ';
        cout << endl;
    }
}