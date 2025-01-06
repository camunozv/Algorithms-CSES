#include <bits/stdc++.h>

#define lli long long int

using namespace std;

vector<lli> build(const vector<lli> &numbers);

int main() {


    int n = 0;
    int q = 0;

    cin >> n;
    cin >> q;

    vector<lli> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<lli> prefix_sum = build(numbers);

    int k = 0;
    int a = 0;
    int b = 0;
    lli result = 0;
    while (k < q) {
        cin >> a;
        cin >> b;

        a -= 1;
        b -= 1;

        if (a > 0) {
            result = prefix_sum[b] - prefix_sum[a - 1];
        } else {
            result = prefix_sum[b];
        }

        cout << result << "\n";
        k++;
    }

    return 0;
}

vector<lli> build(const vector<lli> &numbers) {
    int n = (int) numbers.size();
    vector<lli> prefix_sum = numbers;
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i] + prefix_sum[i - 1];
    }
    return prefix_sum;
}
