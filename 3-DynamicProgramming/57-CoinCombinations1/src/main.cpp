#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &coins, int n)
{

    vector<int> sol(n + 1, 0);
    sol[0] = 1;
    int m = (int)(pow(10, 9) + 7);
    for (int i = 1; i < n + 1; i++)
    {
        for (auto d : coins)
        {
            if (i - d >= 0)
            {
                sol[i] += sol[i - d];
                sol[i] = sol[i] % m;
            }
        }
    }

    return sol[n];
}

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;

    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << solve(coins, x) << "\n";

    return 0;
}