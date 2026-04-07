#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int cities[10];

    for(int i = 0; i < n; i++)
        cities[i] = i;

    int min_cost = 999999;

    // Fix first city as starting point
    do
    {
        int current_cost = 0;

        for(int i = 0; i < n - 1; i++)
        {
            current_cost += cost[cities[i]][cities[i + 1]];
        }

        current_cost += cost[cities[n - 1]][cities[0]];

        if(current_cost < min_cost)
            min_cost = current_cost;

    } while(next_permutation(cities + 1, cities + n));

    cout << "Minimum traveling cost: " << min_cost;

    return 0;
}