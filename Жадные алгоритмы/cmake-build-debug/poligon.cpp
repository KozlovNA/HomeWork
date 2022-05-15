#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

const int max_n = 101;
const int inf = 1e9;

int dp[max_n][2];

int main() {

    vector<int>input;
    for (int i = 0; i < 10; ++i){
        input.push_back(i);
    }

    for (int i = 0; i < input.size(); ++i){
        cout << input[i];
    }



    return 0;
}
