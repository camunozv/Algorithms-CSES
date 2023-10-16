#include <bits/stdc++.h>
#define llui unsigned long int
using namespace std;

pair<string, bool> palindromeReorder(string word);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    pair<string, bool> result = palindromeReorder(characterChain);

    if (result.second == true)
    {
        cout << result.first << "\n";
    }
    else
    {
        cout << "NO SOLUTION\n";
        cout << result.first << "\n";
    }

    return 0;
}

pair<string, bool> palindromeReorder(string word)
{
    llui alphabet[26] = {0};
    llui n = word.length();
    char letter = '0';
    pair<string, bool> result;

    for (llui i = 0; i < n; i++)
    {
        letter = word[i];

        if (letter == 'A')
        {
            alphabet[0] += 1;
        }
        else if (letter == 'B')
        {
            alphabet[1] += 1;
        }
        else if (letter == 'C')
        {
            alphabet[2] += 1;
        }
        else if (letter == 'D')
        {
            alphabet[3] += 1;
        }
        else if (letter == 'E')
        {
            alphabet[4] += 1;
        }
        else if (letter == 'F')
        {
            alphabet[5] += 1;
        }
        else if (letter == 'G')
        {
            alphabet[6] += 1;
        }
        else if (letter == 'H')
        {
            alphabet[7] += 1;
        }
        else if (letter == 'I')
        {
            alphabet[8] += 1;
        }
        else if (letter == 'J')
        {
            alphabet[9] += 1;
        }
        else if (letter == 'K')
        {
            alphabet[10] += 1;
        }
        else if (letter == 'L')
        {
            alphabet[11] += 1;
        }
        else if (letter == 'M')
        {
            alphabet[12] += 1;
        }
        else if (letter == 'N')
        {
            alphabet[13] += 1;
        }
        else if (letter == 'O')
        {
            alphabet[14] += 1;
        }
        else if (letter == 'P')
        {
            alphabet[15] += 1;
        }
        else if (letter == 'Q')
        {
            alphabet[16] += 1;
        }
        else if (letter == 'R')
        {
            alphabet[17] += 1;
        }
        else if (letter == 'S')
        {
            alphabet[18] += 1;
        }
        else if (letter == 'T')
        {
            alphabet[19] += 1;
        }
        else if (letter == 'U')
        {
            alphabet[20] += 1;
        }
        else if (letter == 'V')
        {
            alphabet[21] += 1;
        }
        else if (letter == 'W')
        {
            alphabet[22] += 1;
        }
        else if (letter == 'X')
        {
            alphabet[23] += 1;
        }
        else if (letter == 'Y')
        {
            alphabet[24] += 1;
        }
        else if (letter == 'Z')
        {
            alphabet[25] += 1;
        }
    }

    bool flag = true;

    // if our array has even length then every letter should appear a even number of times
    if (n % 2 == 0)
    {
        llui i = 0;
        bool allEven = alphabet[i] % 2 == 0;
        while (allEven && i < 26)
        {
            allEven = alphabet[i] % 2 == 0;
            i++;
        }

        if (allEven)
        {
            // then we construct the palindrome
        }
        else
        {
            // there is no solution
            result.first = "NO SOLUTION";
            result.second = false;
        }
    }
    else // if our string has odd number of characters then we can have only one letter which appears an odd number of
    // times
    {
        llui i = 0;
        llui k = 0;
        while (i < 26 && k <= 1)
        {
            if (alphabet[i] % 2 != 0)
            {
                k++;
            }
            i++;
        }

        bool oneOdd = k == 1 ? true : false;

        if (oneOdd)
        {
            // then we construct the palindrome
        }
        else
        {
            // there is no solution
            result.first = "NO SOLUTION";
            result.second = false;
        }
    }

    return result;
}
