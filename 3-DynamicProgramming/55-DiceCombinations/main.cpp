#include <bits/stdc++.h>
#define li long int

using namespace std;

li solve(li n, vector<bool> &calculated, vector<li> &value);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<bool> calculated(n, false);
    vector<li> value(n, 0);

    cout << solve(n, calculated, value) << "\n";

    return 0;
}

li solve(li n, vector<bool> &calculated, vector<li> &value) {

    li k = 0;
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return INT_MIN;
    } else if (calculated[n]) {
        return value[n];
    } else {
        for (int i = 1; i < 7; i++) {
            li r = solve(n - i, calculated, value);
            if (r > 0) k += r;
        }

        calculated[n] = true;
        k = k % (((li) pow(10, 7)) + 7);
        value[n] = k;

        return k;
    }

}