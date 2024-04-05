#include <bits/stdc++.h>

using namespace std;

void generate_permutations(int k, int n, string &word, vector<bool> &included, vector<char> &permutation);
int calculate_factorial(int n);
int main()
{

    ios::sync_with_stdio(NULL);
    cin.tie(0);

    string the_string;
    cin >> the_string;

    int n = the_string.length();
    vector<bool> included(n, false);
    vector<char> permutation(n);

    int generated_permutations = calculate_factorial(n);
    cout << generated_permutations << "\n";
    generate_permutations(0, n, the_string, included, permutation);
    return 0;
}

void generate_permutations(int k, int n, string &word, vector<bool> &included, vector<char> &permutation)
{
    if (k == n)
    {
        for (auto x : permutation)
        {
            cout << x;
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (included[i] == false)
            {
                // include the character
                included[i] = true;
                permutation[i] = word[k];
                // code here... // generate the next permutation
                generate_permutations(k + 1, n, word, included, permutation);
                included[i] = false; // uninclude the character, able it to other positions in the permutation
            }
        }
    }
}
int calculate_factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * calculate_factorial(n - 1);
    }
}