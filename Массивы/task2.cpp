#include <iostream>
#include <vector>

using namespace std;

void Worry(vector<bool>* v, unsigned it)
{
    (*v)[it] = true;
}

void Quiet(vector<bool>* v, unsigned it)
{
    (*v)[it] = false;
}

void Come(vector<bool>* v, unsigned it)
{
    if(it > 0)
        (*v).insert((*v).end(), it, false);
    else
        (*v).erase((*v).end() - it, (*v).end());
}

unsigned Worry_count(const vector<bool>& v)
{
    unsigned count{0};
    for(bool i : v)
        if(i)
            ++count;
    return count;
}

int main()
{
    int n{0};
    vector<bool> people(0);
    vector<unsigned> counts(0);
    cin >> n;
    for(int i{0}; i < n; ++i)
    {
        string command;
        unsigned it;
        getline(cin, command, ' ');
        if(command != "WORRY_COUNT")
            cin >> it;

        if(command == "WORRY")
            Worry(&people, it);
        if(command == "QUIET")
            Quiet(&people, it);
        if(command == "COME")
            Come(&people, it);
        if(command == "WORRY_COUNT")
            counts.push_back(Worry_count(people));
    }
    for(unsigned i : counts)
        cout << i << ' ';
}