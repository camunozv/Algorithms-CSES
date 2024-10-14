#include<bits/stdc++.h>
#define li long int

using namespace std;

li solve(int x, vector<int> &coins) {
    vector<li> values(x + 1, 0);
    for (int i = 1; i <= x; i++) {
        values[i] = INT_MAX;
        for (auto c: coins) {
            if (i - c >= 0) {
                values[i] = min(values[i], values[i - c] + 1);
            }
        }
        if (values[i] == INT_MAX) {
            values[x] = -1;
        }
    }
    return values[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, x = 0;
    cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << solve(x, coins) << "\n";
    return 0;
}
