#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, int &n, int &m, int length, string cum, int &best, string &path, vector<vector<bool>> &visited,
         vector<vector<char>> &board);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    cin >> m;

    // need to use a bfs

    vector<vector<char>> labyrinth(n);
    vector<vector<bool>> visited(n);

    for (int i = 0; i < n; i++) {
        vector<char> line(m);
        vector<bool> bool_line(m, false);
        for (int j = 0; j < m; j++) {
            cin >> line[j];
        }
        visited[i] = bool_line;
        labyrinth[i] = line;
    }

    int i = 0;
    int j = 0;

    int i2 = 0;

    while (i < n && labyrinth[i2][j] != 'A') {
        while (j < m && labyrinth[i][j] != 'A') {
            j++;
        }
        if (labyrinth[i][j] == 'A') {
            i2 = i;
        }
        i++;
    }

    int initial_length = 0;
    string cum = "";
    int best = INT_MAX;
    string path = "";

    dfs(i2, j, n, m, initial_length, cum, best, path, visited, labyrinth);

    if (best != INT_MAX) {
        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

void dfs(int i, int j, int &n, int &m, int length, string cum, int &best, string &path, vector<vector<bool>> &visited,
         vector<vector<char>> &board) {

    if (board[i][j] == '#') {
        return;
    } else if (board[i][j] == 'B') {
        if (length < best) {
            best = length;
            path = cum;
        }
        return;
    }

    visited[i][j] = true;

    if (i + 1 < n && !visited[i + 1][j]) {
        cum += 'D';
        length += 1;
        dfs(i + 1, j, n, m, length, cum, best, path, visited, board);
    }

    if (i - 1 >= 0 && !visited[i - 1][j]) {
        cum += 'U';
        length += 1;
        dfs(i - 1, j, n, m, length, cum, best, path, visited, board);
    }

    if (j + 1 < m && !visited[i][j + 1]) {
        cum += 'R';
        length += 1;
        dfs(i, j + 1, n, m, length, cum, best, path, visited, board);
    }

    if (j - 1 >= 0 && !visited[i][j - 1]) {
        cum += 'L';
        length += 1;
        dfs(i, j - 1, n, m, length, cum, best, path, visited, board);
    }
}