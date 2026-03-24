#include <iostream>
using namespace std;

int main()
{
    int a[50], n, i, j, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Insertion Sort
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }

    cout << "Sorted array:\n";
    for(i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}