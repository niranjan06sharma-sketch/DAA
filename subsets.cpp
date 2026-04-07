#include <iostream>
using namespace std;

int set[50], subset[50], n, target;

void subsetSum(int i, int sum, int count)
{
    if(sum == target)
    {
        cout << "{ ";
        for(int j = 0; j < count; j++)
            cout << subset[j] << " ";
        cout << "}" << endl;
        return;
    }

    if(i >= n || sum > target)
        return;

    // Include current element
    subset[count] = set[i];
    subsetSum(i + 1, sum + set[i], count + 1);

    // Exclude current element
    subsetSum(i + 1, sum, count);
}

int main()
{
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++)
        cin >> set[i];

    cout << "Enter target sum: ";
    cin >> target;

    cout << "Subsets with sum " << target << " are:\n";
    subsetSum(0, 0, 0);

    return 0;
}