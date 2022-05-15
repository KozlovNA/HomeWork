#include <iostream>
#include <list>

int main()
{
    int n; std::list<int> stack;
    for(std::cin >> n; n != 0; std::cin >> n)
    {
        if(n > 0)
            stack.push_back(n);
        else if(-n < *(--stack.end()))
            *(--stack.end()) += n;
        else if(!stack.empty())
            stack.pop_back();
    }

    if(stack.empty())
        std::cout << -1;
    else
        std::cout << stack.size() << ' ' << *(--stack.end());
}

