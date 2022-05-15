#include <iostream>
#include <algorithm>
#include <string>

std::string lower(std::string inp)
{
    for(int i = 0; i < inp.length(); ++i)
        inp[i] = tolower(inp[i]);
    return inp;
}

int main()
{
    int n;
    std::cin >> n;
    auto m = new std::string [n];
    for(int i = 0; i < n; ++i)
    {
        std::cin >> m[i];
        m[i] = lower(m[i]);
    }
    std::sort(m, m + n);
    std::string m_popular = m[0];
    int m_counter = 1; int c_counter = 1;
    for(int i = 1; i < n; ++i)
    {
        if(m[i] == m[i-1])
            ++c_counter;
        else if(c_counter > m_counter)
        {
            m_counter = c_counter;
            c_counter = 0;
            m_popular = m[i-1];
        }
    }
    if(c_counter > m_counter)
    {
        m_counter = c_counter;
        m_popular = m[n-1];
    }
    std::cout << m_popular << ' ' << m_counter;
}
