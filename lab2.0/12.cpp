#include <iostream>
#include <string>
using namespace std;

unsigned int get_a_hexadecimal()
{
    string num;
    unsigned int decidemical = 0;
    cin >> num;
    for (char dig : num) {
        if ('0' <= dig && dig <= '9')
            decidemical = 16 * decidemical + dig - '0';
        else if ('A' <= dig && dig <= 'F')
            decidemical = 16 * decidemical + 10 + dig - 'A';
        else
            return 0;
    }
    return decidemical;
}

int main()
{
    cout <<get_a_hexadecimal() <<endl;
    return 0;
}
