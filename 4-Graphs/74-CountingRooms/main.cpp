#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int m = 0;

    cin >> n;
    cin >> m;

    vector<vector<char>> rooms;

    for (int i = 0; i < n;i++){
        vector<char> r (m);
        rooms.push_back(r);
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }

    return 0;
}