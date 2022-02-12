#include <iostream>
using namespace std;

unsigned long get_really_any_hexadecimal();

unsigned long get_really_any_hexadecimal() {
    string num;
    unsigned int decidemical = 0;
    cin >> num;
    for (char dig : num) {
        if ('0' <= dig && dig <= '9')
            decidemical = 16 * decidemical + dig - '0';
        else if ('A' <= dig && dig <= 'F')
            decidemical = 16 * decidemical + 10 + dig - 'A';
        else if ('a' <= dig && dig <='f')
            decidemical = 16 * decidemical + 10 + dig - 'a';
    }
    return decidemical;
}

int main()
{
    cout <<get_really_any_hexadecimal() <<endl;
    return 0;
}
