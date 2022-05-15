#include <iostream>

struct Item
{
    int cost, weight;
};

int knapsack(int M, struct Item arr[], int n)
{
    if(n == 1)
        return arr[0].cost;
    int cur_cost, max_cost = 0;
    for (int i = 0; i < n; ++i)
        if(M >= arr[i].weight)
        {
            std::swap(arr[i], arr[n-1]);
            cur_cost = knapsack(M - arr[n-1].weight, arr, n-1) + arr[n-1].cost;
            std::swap(arr[i], arr[n-1]);
            if(cur_cost > max_cost)
                max_cost = cur_cost;
        }
    return max_cost;
}

int main()
{
    int M, n;
    struct Item arr[100];
    std::cin >> n >> M;
    for(int i = 0; i < n; ++i)
        std::cin >> arr[i].cost >> arr[i].weight;
    std::cout << knapsack(M, arr, sizeof(arr) / sizeof(arr[0]));
}