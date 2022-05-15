#include <iostream>
#include <string>
#include <algorithm>
#include <list>

std::string lower(std::string inp)
{
    for(int i = 0; i < inp.length(); ++i)
        inp[i] = tolower(inp[i]);
    return inp;
}

int main()
{
    int n; std::string inp;
    std::list<std::string> arr;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> inp;
        inp = lower(inp);
        arr.push_back(inp);
    }
    arr.sort(); arr.reverse();
    std::cout << *(arr.begin()) << ' ';
    auto jt = arr.begin();
    for(auto it = (++arr.begin()); it != arr.end(); ++it, ++jt)
    {
        if((*jt) != (*it))
            std::cout << (*it) << ' ';
    }
}
