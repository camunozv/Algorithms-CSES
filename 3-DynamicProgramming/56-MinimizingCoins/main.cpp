#include<bits/stdc++.h>

using namespace std;

int solve(int x, vector<int> &coins, vector<bool> &value, vector<int> &calculated);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int x = 0;

    cin >> n;
    cin >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> possible_values(x + 1, 0);
    vector<bool> calculated_values(x + 1, false);

    cout << "\n";

    int solution = solve(x, coins, calculated_values, possible_values);

    cout << solution << "\n";
    return 0;
}

int solve(int x, vector<int> &coins, vector<bool> &value, vector<int> &calculated) {
    if (x == 0) {
        return 0;
    } else if (x < 0) {
        return INT_MAX + x;
    } else if (value[x]) {
        return calculated[x];
    } else {
        int best = INT_MAX;
        for (auto c: coins) {
            best = min(best, solve(x - c, coins, value, calculated) + 1);
        }
        value[x] = true;
        calculated[x] = best;
        return best;
    }
}

/*
 * 1 1
1000000
 * */