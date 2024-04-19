#include <bits/stdc++.h>

using namespace std;

void creating_strings(int k, int n, vector<bool> &included, string &the_string, string &text, set<string> &the_set);
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    string the_string;
    cin >> the_string;

    int n = the_string.size();
    string permutation = the_string;

    set<string> string_set;
    vector<bool> included(n, false);

    creating_strings(0, n, included, the_string, permutation, string_set);

    cout << string_set.size() << "\n";

    for (auto x : string_set)
    {
        cout << x << "\n";
    }

    return 0;
}

void creating_strings(int k, int n, vector<bool> &included, string &the_string, string &text, set<string> &the_set)
{
    if (k == n)
    {
        string inserted_string = text;
        the_set.insert(inserted_string); // By inserting new strings in a set we delete repeated permutations :D
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (included[i] == false)
            {
                included[i] = true;
                text[k] = the_string[i];
                creating_strings(k + 1, n, included, the_string, text, the_set);
                included[i] = false;
            }
        }
    }
}