#include <bits/stdc++.h>

using namespace std;

long long two_knights(long long n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << two_knights(i) << "\n";
    }
    return 0;
}

long long two_knights(long long n) {
    long long result = ((n * n) * ((n * n) - 1)) / 2;
    result -= 4 * ((n - 1) * (n - 2));
    return result;
}