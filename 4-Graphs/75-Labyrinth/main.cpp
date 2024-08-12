#include <bits/stdc++.h>

using namespace std;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    cin >> m;

    vector<vector<char>> labyrinth(n);

    for(int i = 0; i < n; i++) {
        vector<char> line(m);
        for(int j = 0; j < m; j++) {
            cin >> line[j];
        }
        labyrinth[i] = line;
    }

    return 0;
}