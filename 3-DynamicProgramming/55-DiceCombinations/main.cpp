#include <bits/stdc++.h>

#define li long int

using namespace std;

li solve(vector<li> &numbers, int n) {
    numbers[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int c = 1; c < 7; c++) {
            if (i - c >= 0) {
                numbers[i] += numbers[i - c];
            }
        }
        numbers[i] = numbers[i] % ((li) pow(10, 9) + 7);
    }
    return numbers[n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<li> values(n + 1, 0);

    cout << solve(values, n + 1) << "\n";
    return 0;
}