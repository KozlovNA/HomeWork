#include <iostream>
using namespace std;

struct cont
{
    unsigned int price;
    unsigned int sweets;
};

int main()
{
    cont arr[1000];
    int n;
    unsigned int money;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i].price >> arr[i].sweets;
    cin >> money;

    bool f = true;
    while (f)
    {
        f = false;
        for (int j = 0; j < n - 1; ++j)
            if (arr[j].price > arr[j+1].price)
            {
                swap(arr[j], arr[j+1]);
                f = true;
            }
    }

    f = true;
    unsigned int cont_count = 0, sweets_count = 0;
    for (int i = 0; f; ++i)
    {
        if (money >= arr[i].price)
        {
            money -= arr[i].price;
            ++cont_count;
            sweets_count += arr[i].sweets;
        }
        else
            f = false;
    }

    cout << cont_count << ' ' << sweets_count;

}