#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, int &n, int &m, vector<vector<char>> &board, vector<vector<bool>> &visited);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int m = 0;
    int n = 0;

    cin >> n;
    cin >> m;

    vector<vector<char>> rooms(n);
    vector<vector<bool>> visited(n);

    for (int i = 0; i < n; i++) {
        vector<char> line(m);
        vector<bool> bool_line(m, false);
        for (int j = 0; j < m; j++) {
            cin >> line[j];
        }
        visited[i] = bool_line;
        rooms[i] = line;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && rooms[i][j] != '#') {
                dfs(i, j, n, m, rooms, visited);
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;

}

void dfs(int i, int j, int &n, int &m, vector<vector<char>> &board, vector<vector<bool>> &visited) {

    if (board[i][j] == '#') {
        return;
    }

    visited[i][j] = true;

    if (i + 1 < n && !visited[i + 1][j]) {
        dfs(i + 1, j, n, m, board, visited);
    }
    if (i - 1 >= 0 && !visited[i - 1][j]) {
        dfs(i - 1, j, n, m, board, visited);
    }
    if (j + 1 < m && !visited[i][j + 1]) {
        dfs(i, j + 1, n, m, board, visited);
    }
    if (j - 1 >= 0 && !visited[i][j - 1]) {
        dfs(i, j - 1, n, m, board, visited);
    }

}