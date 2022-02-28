#include <iostream>
using namespace std;

struct Protoss {
    unsigned long long int id;
    unsigned int health, shield, position[2];
    char name[100];
};

unsigned int count_wounded(Protoss *army, unsigned int n, unsigned int
threshold)
{
    int wounded = 0;
    for (int i = 0; i<n; ++i)
    {
        cout << army[i].name << endl;
        if (army[i].health < threshold)
            ++wounded;
    }
    return wounded;
}

int main()
{
    Protoss army[10];
    for (int i = 0; i < 10; i++)
    {
        army[i].id = i;
        cin >> army[i].health >> army[i].shield >> army[i].position[0]
                 >> army[i].position[1] >> army[i].name;
    }
    cout << count_wounded(army, 10, 100);
    cout << endl;
    return 0;
}