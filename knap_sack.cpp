#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[50], value[50];

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int dp[50][50];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i-1] <= w)
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum value in knapsack = " << dp[n][W];

    return 0;
}