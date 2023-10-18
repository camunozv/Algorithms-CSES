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

    string sideA;
    string sideB;
    llui k = 0;
    llui b = 0;
    if (hasEvenLength && allEven(mapping))
    {

        for (int i = 0; i < 26; i++)
        {
            k = *(mapping + i);
            b = k / 2;
            while (k > b)
            {
                sideA += char(i + 65);
                k--;
            }

            k = *(mapping + 25 - i);
            b = k / 2;
            while (k > b)
            {
                sideB += char(90 - i);
                k--;
            }
        }
        cout << sideA + sideB << "\n";
    }
    else if (!hasEvenLength && atLeastOneOdd(mapping))
    {
        string middle;
        for (int i = 0; i < 26; i++)
        {
            k = *(mapping + i);
            if (k % 2 == 0)
            {
                b = k / 2;
                while (k > b)
                {
                    sideA += char(i + 65);
                    k--;
                }
            }
        }

        for (int i = 25; i >= 0; i--)
        {
            k = *(mapping + 25 - i);
            if (k % 2 == 0)
            {
                b = k / 2;
                while (k > b)
                {
                    sideB += char(90 - i);
                    k--;
                }
            }
        }

        for (int i = 0; i < 26; i++)
        {
            k = *(mapping + i);
            if (k % 2 != 0)
            {
                while (k > 0)
                {
                    middle += char(i + 65);
                    k--;
                }
            }
        }

        cout << sideA + middle + sideB << "\n";
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