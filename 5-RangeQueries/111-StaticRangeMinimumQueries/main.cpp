#include<bits/stdc++.h>

using namespace std;

int my_min(int i, int k, vector<int> &base_arr) {
    int miin = base_arr[i];
    while (i <= k) {
        if (base_arr[i] < miin) {
            miin = base_arr[i];
        }
        i++;
    }
    return miin;
}

vector<int> build(vector<int> &base_arr, int &range_size) {
    int i = 0, k = i + range_size - 1;
    vector<int> return_arr(base_arr.size(), 0);
    while (k < base_arr.size()) {
        return_arr[i] = my_min(i, k, base_arr);
        i++;
        k = i + range_size - 1;
    }
    return return_arr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, q = 0;
    cin >> n;
    cin >> q;
    vector<int> base_arr(n);
    for (int i = 0; i < n; i++) {
        cin >> base_arr[i];
    }

    int sparse_size = (int) log2(n);
    vector<vector<int>> sparse_table(sparse_size + 1);
    sparse_table[0] = base_arr;

    int range_size = 2;
    for (int i = 1; i < sparse_size + 1; i++) {
        vector<int> row = build(base_arr, range_size);
        sparse_table[i] = row;
        range_size *= 2;
    }

    for(int i = 0; i < sparse_size + 1; i++) {
        for(int j = 0; j < n; j++) {
            cout << sparse_table[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}