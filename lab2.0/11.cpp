#include <iostream>
using namespace std;

char unleveling(char c);
char get_a_letter();

//-------------------------------------------------------------

char unleveling(char c)
{
    if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
    return c;
}

char get_a_letter() {
    char c;
    do
    {
        cin.get(c);
        if (c >= 65 && c <= 90 || c >= 97 && c <= 122) {
            return c;
        }
    } while (c != '\n');
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout <<unleveling(get_a_letter());
    cout <<endl;
    return 0;
}
