#include <iostream>
using namespace std;

unsigned greatest_common_subseq_rec(
        int const *seqA, unsigned const sizeA,
        int const *seqB, unsigned const sizeB,
        int **memoization
        ){
    if (0 == sizeA || 0 == sizeB) {
        if (0 == memoization[sizeA][sizeB]) memoization[sizeA][sizeB] = 1;
        return memoization[sizeA][sizeB];
    }

    if (seqA[sizeA - 1] == seqB[sizeB - 1]) {
        if (0 == memoization[sizeA - 1][sizeB - 1]) memoization[sizeA - 1][sizeB - 1] =
                greatest_common_subseq_rec(seqA, sizeA - 1, seqB, sizeB - 1, memoization);
        return memoization[sizeA - 1][sizeB - 1] + 1;
    }

    if (0 == memoization[sizeA - 1][sizeB])
        memoization[sizeA - 1][sizeB] =
                greatest_common_subseq_rec(seqA, sizeA - 1, seqB, sizeB, memoization);

    if (0 == memoization[sizeA][sizeB - 1])
        memoization[sizeA][sizeB - 1] =

                greatest_common_subseq_rec(seqA, sizeA, seqB, sizeB - 1, memoization);

    return std::max(memoization[sizeA - 1][sizeB], memoization[sizeA][sizeB - 1]);
}

int main() {
    int n;
    cin >> n;
    int *seqA = new int [n];
    for (int i = 0; i < n; ++i){
        cin >> *(seqA + i);
    }
    int m;
    cin >> m;
    int *seqB = new int [m];
    for (int i = 0; i < m; ++i){
        cin >> *(seqB + i);
    }

    int** memoization = new int*[n];
    for (int i = 0; i < n; ++i) {
        memoization[i] = new int [m];
    }

    int result = greatest_common_subseq_rec(seqA, sizeof(seqA)/sizeof(*seqA), seqB, sizeof(seqB)/sizeof(*seqB), memoization);
    cout << result;

    return 0;
}