#include <bits/stdc++.h>

#define li long int

using namespace std;

li solve(vector<li> &coins, li x, li &n, vector<bool> &calculated, vector<li> &value);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    li n = 0; // number of coins
    li x = 0; // target sum

    cin >> n;
    cin >> x;

    vector<li> coins(n);
    vector<bool> calculated(x + 1, false);
    vector<li> value(x + 1);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << solve(coins, x, n, calculated, value) << "\n";

    return 0;
}

li solve(vector<li> &coins, li x, li &n, vector<bool> &calculated, vector<li> &value) {

    li k = 0;

    if (x == 0) {
        k = 1;
    } else if (x < 0) {
        k = -1;
    } else if (calculated[x]) {
        k = value[x];
    } else {
        li test = 0;
        for (int i = 0; i < n; i++) {
            test = solve(coins, x - coins[i], n, calculated, value);
            if (test > 0) {
                k += test;
            }
        }

        calculated[x] = true;
        k = (k % (li) (pow(10, 9) + 7));
        value[x] = k;
    }

    return k;
}