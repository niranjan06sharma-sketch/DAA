#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 256

void badCharHeuristic(string str, int size, int badchar[SIZE])
{
    for(int i = 0; i < SIZE; i++)
        badchar[i] = -1;

    for(int i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void boyerMoore(string text, string pattern)
{
    int m = pattern.size();
    int n = text.size();

    int badchar[SIZE];

    badCharHeuristic(pattern, m, badchar);

    int shift = 0;

    while(shift <= (n - m))
    {
        int j = m - 1;

        while(j >= 0 && pattern[j] == text[shift + j])
            j--;

        if(j < 0)
        {
            cout << "Pattern found at position: " << shift << endl;

            shift += (shift + m < n) ? m - badchar[text[shift + m]] : 1;
        }
        else
        {
            shift += max(1, j - badchar[text[shift + j]]);
        }
    }
}

int main()
{
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    boyerMoore(text, pattern);

    return 0;
} 