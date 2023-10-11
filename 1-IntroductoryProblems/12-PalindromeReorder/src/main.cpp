#include <bits/stdc++.h>
using namespace std;

string palindromeReorder (string word);
int main()
{
    // To increase the velocity.
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    string newWord = palindromeReorder(characterChain);

    cout << "Char chain: " << characterChain << "\n";
    cout << "New word: " << newWord <<  "\n";

    return 0;
}

string palindromeReorder (string word)
{
    word += "kbron";
    return word;
}

    // for (long unsigned int i = 0; i < characterChain.length(); i++)
    // {
    //     cout << characterChain[i] << " ";
    // }

    // cout << "\n";

    // long unsigned int ord = 0;
    // for (long unsigned int i = 0; i < characterChain.length(); i++)
    // {
    //     ord = characterChain[i];
    //     cout << ord << " ";
    // }

    // cout << "Length of the string is: " << characterChain.length() / 2 << "\n";