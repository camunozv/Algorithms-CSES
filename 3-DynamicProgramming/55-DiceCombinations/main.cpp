#include <bits/stdc++.h>
#define li long int

using namespace std;

li solve(li n, vector<bool> &calculated, vector<li> &value);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<bool> calculated(n + 1, false);
    vector<li> value(n + 1, 0);

    cout << solve(n, calculated, value) << "\n";

    return 0;
}

li solve(li n, vector<bool> &calculated, vector<li> &value) {

    li k = 0;
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 0;
    } else if (calculated[n]) {
        return value[n];
    } else {
        for (int i = 1; i < 7; i++) {
            k += solve(n - i, calculated, value);
        }

        calculated[n] = true;
        k = k % (((li) pow(10, 9)) + 7);
        value[n] = k;

        return k;
    }

}