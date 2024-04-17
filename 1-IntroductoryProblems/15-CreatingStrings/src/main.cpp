#include <bits/stdc++.h>

using namespace std;

void lexi_perm(int k, int n, string &text, vector<bool> &included, string &the_string, vector<vector<char>> &non_repeat, int &count, vector<string> &save);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string permutation;
    cin >> permutation;

    int n = permutation.length();
    vector<vector<char>> non_repeat;

    for (int i = 0; i < n; i++)
    {
        vector<char> store(1);
        non_repeat.push_back(store);
    }

    string text = permutation;
    vector<bool> included(n, false);
    vector<string> save;
    int count = 0;
    sort(permutation.begin(), permutation.end());
    lexi_perm(0, n, text, included, permutation, non_repeat, count, save);

    cout << count << "\n";
    for (auto s : save)
    {
        cout << s << "\n";
    }
    return 0;
}

void lexi_perm(int k, int n, string &text, vector<bool> &included, string &the_string, vector<vector<char>> &non_repeat, int &count, vector<string> &save)
{
    if (k == n)
    {
        count++;
        save.push_back(text);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            char character = the_string[i];
            bool able = non_repeat[k][0] != character;
            if (able && included[i] == false)
            {
                non_repeat[k][0] = character;
                included[i] = true;
                text[k] = character;
                lexi_perm(k + 1, n, text, included, the_string, non_repeat, count, save);
                included[i] = false;
            }
        }
    }
}
