# include <bits/stdc++.h>

using namespace std;

int solve(vector<int> numbers, int n);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> numbers(n + 1);

    for (int i = 1; i < n + 1; i++) {
        cin >> numbers[i];
    }

    cout << solve(numbers, n) << "\n";

    return 0;
}

int solve(vector<int> numbers, int n) {

    int rounds = 1; // minimum number of rounds

    vector<int> number_map(n + 1);

    for (int i = 1; i < n + 1; i++) {
        number_map[numbers[i]] = i;
    }

    for (int j = 1; j < n; j++) {
        if (number_map[j] > number_map[j + 1]) {
            rounds++;
        }
    }
    return rounds;
}