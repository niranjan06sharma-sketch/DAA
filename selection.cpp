#include <iostream>
using namespace std;

int main()
{
    int a[50], n, i, j, min, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    cout << "Sorted array:\n";
    for(i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}