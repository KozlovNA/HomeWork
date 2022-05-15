#include <iostream>
#include <list>
#include <algorithm>
#include <string>

int main()
{
    std::list<int> m; int var1; int var2;
    std::string s; std::cin >> s;
    for(; s != "="; std::cin >> s)
    {
        if(s < "0")
        {
            var1 = *(--m.end()); m.pop_back();
            var2 = *(--m.end()); m.pop_back();
            if(s == "+")
                m.push_back(var1 + var2);
            else if(s == "-")
                m.push_back(var2 - var1);
            else if(s == "*")
                m.push_back(var1 * var2);
        }
        else
            m.push_back(std::stoi(s));

    }
    std::cout << *m.begin();
}
