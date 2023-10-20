#include <bits/stdc++.h>
using namespace std;

int *characterMapping(string chain, int n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    int characterChainLength = characterChain.length();
    int *mapping = characterMapping(characterChain, characterChainLength);

    string sideA;
    string sideB;
    int k = 0;
    int b = 0;
    int middle = -1;
    int middleAppearances = 0;

    int i = 0;
    while (i < 26 && middleAppearances <= 1)
    {
        k = mapping[i];
        if (k % 2 != 0)
        {
            middle = i;
            middleAppearances++;
        }
        i++;
    }

    if (middleAppearances > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            k = mapping[i];
            b = (k / 2) + (k % 2);
            while (k > b)
            {
                cout << char(i + 65);
                k--;
            }
        }

        if (middleAppearances == 1)
        {
            cout << char(middle + 65);
        }

        for (int i = 25; i >= 0; i--)
        {
            k = mapping[i];
            b = (k / 2) + (k % 2);
            while (k > b)
            {
                cout << char(i + 65);
                k--;
            }
        }
    }

    cout << "\n";

    delete[] mapping;
    mapping = NULL;
    return 0;
}

int *characterMapping(string chain, int n)
{
    int *array = new int[26];
    for (int i = 0; i < n; i++)
    {
        array[int(chain[i]) - 65]++;
    }
    return array;
}
