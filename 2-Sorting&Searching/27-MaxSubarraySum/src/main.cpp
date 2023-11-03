#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    long n = 0;
    cin >> n;

    long array[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Kadane's algorithm
    long sum = 0;
    long best = LONG_MIN;
    for (long i = 0; i < n; i++)
    {
        sum = max(sum + array[i], array[i]);
        best = max(sum, best);
    }

    cout << best << "\n";
    return 0;
}