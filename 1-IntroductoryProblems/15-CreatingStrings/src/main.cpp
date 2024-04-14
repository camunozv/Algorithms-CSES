#include <bits/stdc++.h>

using namespace std;

void generate_all(string permut, string reverse_permut);
string reverse_string(string the_string);
int main()
{

    // The complexity must be of O(n!) because the max input size is of 8
    ios::sync_with_stdio(0);
    cin.tie(0);

    string permut;
    cin >> permut;

    sort(permut.begin(), permut.end());
    string rev = reverse_string(permut);

    generate_all(permut, rev);
    return 0;
}

void generate_all(string permut, string reverse_permut)
{
    if (permut == reverse_permut)
    {
        return;
    }
    else
    {
        for (int i = permut.length() - 1; i >= 1; i--)
        {
            if (permut[i] > permut[i - 1])
            {
                char temp = permut[i - 1];
                permut[i - 1] = permut[i];
                permut[i] = temp;
                sort(permut.begin() + i, permut.end());
                temp = permut[i];
                permut[i] = permut[0];
                cout << permut << "\n";
                break;
            }
        }
        generate_all(permut, reverse_permut);
    }
}

string reverse_string(string the_string)
{
    int half = ((the_string.length() - 1) / 2);
    int rev_i = the_string.length() - 1;

    for (int i = 0; i <= half; i++)
    {
        char temp = the_string[rev_i];
        the_string[rev_i] = the_string[i];
        the_string[i] = temp;
        rev_i--;
    }

    return the_string;
}