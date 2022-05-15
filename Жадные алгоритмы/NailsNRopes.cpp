#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string data;
    auto nails = new int [100]; auto res = new int [100]; int cou = 0;
    getline(cin, data);
    {
        int i = 0;
        int j = 1;
        while (i < data.length() - 1)
        {
            for (; j < data.length() && data[j] != ' '; ++j);
            nails[cou] = stoi(data.substr(i, j - i));
            i = j;
            ++cou;
            ++j;
        }
    }
    sort(nails, nails + cou);
    res[0] = 1e9; res[1] = nails[1] - nails[0];
    for(int i = 2; i < cou; ++i)
        res[i] = min(res[i - 1], res[i - 2]) + nails[i] - nails[i - 1];
    cout << res[cou - 1];
    delete[] nails; delete[] res;
}
