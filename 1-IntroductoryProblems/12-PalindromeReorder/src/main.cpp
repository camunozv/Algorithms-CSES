#include <bits/stdc++.h>
#define llui unsigned long int
using namespace std;

int *characterMapping(string chain, llui n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    int *mapping = characterMapping(characterChain, characterChain.length());

    for (int i = 0; i < 25; i++)
    {
        cout << *(mapping + i) << " ";
    }

    delete mapping;
    mapping = NULL;
    return 0;
}

int *characterMapping(string chain, llui n)
{
    int *array = new int[25];

    for (llui i = 0; i < n; i++)
    {
        array[int(chain[i]) - 65]++;
    }

    return array;
}

bool allEven (int *array)
{
    bool allEven = true;
    for(int i = 0; i < 25; i++)
    {
        if (*(array + i) % 2 != 0)
        {
            allEven = false;
        }
    }
    return allEven;
}

bool atLeastOneOdd (int *array)
{
    int counter = 0;
    for(int i = 0; i < 25; i++)
    {
        if (*(array + i) % 2 != 0)
        {
            counter++;
        }
    }
    return counter == 1 ? true : false;
}