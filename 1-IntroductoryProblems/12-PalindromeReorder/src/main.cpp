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
    bool flag = true;
    llui index = 0;
    llui j = word.length() - 1;
    llui i = 0;
    llui k = 0;
    while (index < (word.length() / 2) && flag)
    {
        while (word[i] == word[j] && i < (word.length() / 2))
        {
            j--;
            i++;
        }

        k = i + 1;
        while (k < j && word[i] != word[k])
        {
            k++;
        }

        if (word[i] == word[k])
        {
            char letter = word[k];
            word[k] = word[j];
            word[j] = letter;
        }
        else
        {
            flag = false;
        }
        index++;
    }

    pair<string, bool> result;
    result.first = word;
    result.second = flag;
    return result;
}
