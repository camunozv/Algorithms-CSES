#include <bits/stdc++.h>

using namespace std;

void generate_permutations(string the_string, vector<char> &permutation, vector<bool> &included, int k, int n);
void generate_subsets(vector<int> &base_array, vector<bool> &included, int k, int n);
int main()
{

    // The complexity must be of O(n!) because the max input size is of 8
    ios::sync_with_stdio(0);
    cin.tie(0);

    // GENERATE PERMUTATIONS TEST:
    // string string_to_sort;
    // cin >> string_to_sort;

    // sort(string_to_sort.begin(), string_to_sort.end());

    // vector<bool> included(string_to_sort.length(), false);
    // vector<char> permutation(string_to_sort.length());

    // generate_permutations(string_to_sort, permutation, included, 0, string_to_sort.length());

    // GENERATE SUBSETS TEST:

    int n = 0;

    cin >> n;

    vector<int> base_vector(n);
    vector<bool> included(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> base_vector[i];
    }

    generate_subsets(base_vector, included, 0, n);

    return 0;
}

void generate_permutations(string the_string, vector<char> &permutation, vector<bool> &included, int k, int n)
{

    if (k == n) // if the position is the size of the string then we are ended
    {
        for (auto x : permutation)
        {
            cout << x << " ";
        }

        cout << "\n";
    }
    else
    {
        // call the funciton, generate the next permutation
        for (int i = 0; i < n; i++)
        {

            if (included[i] == false)
            {
                included[i] = true;
                permutation[k] = the_string[i];
                generate_permutations(the_string, permutation, included, k + 1, n);
                included[i] = false;
            }
        }
    }
}

void generate_subsets(vector<int> &base_array, vector<bool> &included, int k, int n)
{
    if (k == n)
    {
        // print the permutation
        for (int i = 0; i < n; i++)
        {
            if (included[i] == true)
            {
                cout << base_array[i] << " ";
            }
        }
        cout << "\n";
    }
    else
    {
        // include element, then procede to the next one
        if (included[k] == false)
        {
            included[k] = true;
            generate_subsets(base_array, included, k + 1, n);
        }

        included[k] = false;
        generate_subsets(base_array, included, k + 1, n);
    }
}