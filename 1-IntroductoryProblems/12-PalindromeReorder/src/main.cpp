#include <bits/stdc++.h>
#define llui unsigned long int
using namespace std;

llui *characterMapping(string chain, llui n);
bool allEven(llui *array);
bool atLeastOneOdd(llui *array);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    llui characterChainLength = characterChain.length();
    llui *mapping = characterMapping(characterChain, characterChainLength);

    bool hasEvenLength = characterChainLength % 2 == 0 ? true : false;

    if (hasEvenLength && allEven(mapping))
    {
        llui k = 0;
        for (int i = 0; i < 26; i++)
        {
            k = *(mapping + i);
            while (k > *(mapping + i)/2)
            {
                cout << char(i + 65);
                k--;
            }
        }

        for (int i = 25; i >= 0; i--)
        {
            k = *(mapping + i);
            while (k > *(mapping + i)/2)
            {
                cout << char(i + 65);
                k--;
            }
        }

        cout << "\n";
    }
    else if (!hasEvenLength && atLeastOneOdd(mapping))
    {
        string middle;
        // build the palindrome
    }
    else
    {
        cout << "NO SOLUTION \n";
    }

    delete mapping;
    mapping = NULL;
    return 0;
}

llui *characterMapping(string chain, llui n)
{
    llui *array = new llui[26];
    for (llui i = 0; i < n; i++)
    {
        array[int(chain[i]) - 65]++;
    }
    return array;
}

bool allEven(llui *array)
{
    bool allEven = true;
    for (int i = 0; i < 26; i++)
    {
        if (*(array + i) % 2 != 0)
        {
            allEven = false;
        }
    }
    return allEven;
}

bool atLeastOneOdd(llui *array)
{
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (*(array + i) % 2 != 0)
        {
            counter++;
        }
    }
    return counter == 1 ? true : false;
}