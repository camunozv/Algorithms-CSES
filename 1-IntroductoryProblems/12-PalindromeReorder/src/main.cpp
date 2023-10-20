#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int mapping[26] = {0};
    for (char character : str)
    {
        mapping[character - 65]++;
    }

    int k = 0;
    int middle = 0;
    int oddAppearance = 0;
    int r = 0;
    while (r < 26 && oddAppearance <= 1)
    {
        k = mapping[r];
        if (k % 2 != 0)
        {
            middle = r;
            oddAppearance++;
        }
        r++;
    }

    if (oddAppearance > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        int b = 0;
        for (int i = 0; i < 26; i++)
        {
            k = mapping[i];
            b = (k / 2) + (k % 2);
            while (k > b)
            {
                cout << char(i + 65);
                k--;
            }
        }

        if (oddAppearance == 1)
        {
            cout << char(middle + 65);
        }

        for (int i = 25; i >= 0; i--)
        {
            k = mapping[i];
            b = (k / 2) + (k % 2);
            while (k > b)
            {
                cout << char(i + 65);
                k--;
            }
        }
    }
    cout << "\n";
    return 0;
}
