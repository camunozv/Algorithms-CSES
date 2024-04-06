#include <bits/stdc++.h>

using namespace std;

void generate_next(string &initial);
int main()
{

    ios::sync_with_stdio(NULL);
    cin.tie(0);

    string the_string;
    cin >> the_string;

    sort(the_string.begin(), the_string.end());

    // int n = the_string.length() - 1;

    // generate_all(the_string, n);

    generate_next(the_string);
    return 0;
}

// 1. sort the string in alphabetical order.
// 2. create the algorithm to generate the next permutation
// 3. create the whole program.

// 2.1. Find two elements in which a[j] < a[j + 1]
// 2.2. Invert those elements such that a[j] = a[j + 1] & a[j+1] = a[j]
// 2.3. Organize everything from position a[j + 1] until the end of the string.
// 2.4. If no pair such that a[j] < a[j + 1] is found means we have finished, bce the
// string is completely inverted.

void generate_next(string &initial)
{
    int n = initial.length();
    int i = n - 1;
    bool done = false;
    do
    {
        if (initial[i - 1] < initial[i])
        {
            char temp = initial[i - 1];
            initial[i - 1] = initial[i];
            initial[i] = temp;
            sort(initial.begin() + i, initial.end());
            cout << initial << "\n";
            generate_next(initial);
            done = true;
        }
        i--;
    } while (i >= 1 && !done);
}
