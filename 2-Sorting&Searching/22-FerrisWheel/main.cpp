#include <bits/stdc++.h>

using namespace std;

int assign_gondola(vector<int> &kids_weight, int x);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int x = 0;
    cin >> n;
    cin >> x;

    vector<int> kids_weight(n);

    for (int i = 0; i < n; i++) {
        cin >> kids_weight[i];
    }

    sort(kids_weight.begin(), kids_weight.end());

    int result = assign_gondola(kids_weight, x);

    cout << result << "\n";
    return 0;
}

int assign_gondola(vector<int> &kids_weight, int x) {
    int assigned_gondolas = 0;
    int inferior = 0;
    int superior = kids_weight.size() - 1;
    while (inferior <= superior) {
        if ((kids_weight[inferior] + kids_weight[superior]) <= x) {
            inferior++;
        }
        superior--;
        assigned_gondolas++;
    }
    return assigned_gondolas;
}