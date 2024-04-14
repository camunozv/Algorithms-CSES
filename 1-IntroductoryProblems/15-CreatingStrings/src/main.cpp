#include <bits/stdc++.h>

using namespace std;

void lexi_perm(int k, int n, string &text, vector<bool> &included, string &the_string, vector<vector<char>> &non_repeat);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string permutation;
    cin >> permutation;

    int n = permutation.length();
    vector<vector<char>> non_repeat(n);
    string text = permutation;
    vector<bool> included(n, false);

    sort(permutation.begin(), permutation.end());

    lexi_perm(0, n, text, included, permutation, non_repeat);
    return 0;
}

void lexi_perm(int k, int n, string &text, vector<bool> &included, string &the_string, vector<vector<char>> &non_repeat)
{
    if (k == n)
    {
        cout << text << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            bool able = true;
            int j = 0;
            int r = non_repeat[k].size();
            char character = the_string[i];
            while (j < r && able)
            {
                able = non_repeat[k][j] != character;
                j++;
            }

            if (able && included[i] == false)
            {
                non_repeat[k].push_back(character);
                included[i] = true;
                text[k] = character;
                lexi_perm(k + 1, n, text, included, the_string, non_repeat);
                included[i] = false;
            }
        }
    }
}