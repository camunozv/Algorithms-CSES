#include <bits/stdc++.h>

using namespace std;

void bfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited, vector<vector<int>> &distance,
         vector<vector<char>> &step) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    distance[i][j] = 0;
    pair<int, int> p;
    p.first = i, p.second = j;
    q.push(p);
    int n = board.size(), m = board[0].size();
    int k = 0, r = 0;
    while (!q.empty() && (board[k][r] != 'B')) {
        pair<int, int> node = q.front();
        if (board[node.first][node.second] == 'B') {
            k = node.first;
            r = node.second;
            continue;
        }
        q.pop();
        if (node.first + 1 < n && !visited[node.first + 1][node.second] && board[node.first + 1][node.second] != '#') {
            pair<int, int> a = {node.first + 1, node.second};
            q.push(a);
            visited[node.first + 1][node.second] = true;
            step[node.first + 1][node.second] = 'D';
            distance[node.first + 1][node.second] = distance[node.first][node.second] + 1;
        }

        if (node.first - 1 >= 0 && !visited[node.first - 1][node.second] && board[node.first - 1][node.second] != '#') {
            pair<int, int> a = {node.first - 1, node.second};
            q.push(a);
            visited[node.first - 1][node.second] = true;
            step[node.first - 1][node.second] = 'U';
            distance[node.first - 1][node.second] = distance[node.first][node.second] + 1;
        }

        if (node.second - 1 >= 0 && !visited[node.first][node.second - 1] &&
            board[node.first][node.second - 1] != '#') {
            pair<int, int> a = {node.first, node.second - 1};
            q.push(a);
            visited[node.first][node.second - 1] = true;
            step[node.first][node.second - 1] = 'L';
            distance[node.first][node.second - 1] = distance[node.first][node.second] + 1;
        }

        if (node.second + 1 < m && !visited[node.first][node.second + 1] && board[node.first][node.second + 1] != '#') {
            pair<int, int> a = {node.first, node.second + 1};
            q.push(a);
            visited[node.first][node.second + 1] = true;
            step[node.first][node.second + 1] = 'R';
            distance[node.first][node.second + 1] = distance[node.first][node.second] + 1;
        }

    }

}

void get_path(int i, int j, stack<char> &path, vector<vector<char>> &step) {
    if (step[i][j] != 'A') {
        char letter = step[i][j];
        path.push(letter);
        if (letter == 'R') {
            get_path(i, j - 1, path, step);
        } else if (letter == 'L') {
            get_path(i, j + 1, path, step);
        } else if (letter == 'U') {
            get_path(i + 1, j, path, step);
        } else if (letter == 'D') {
            get_path(i - 1, j, path, step);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<char>> board(n);
    vector<vector<bool>> visited(n);
    vector<vector<int>> distance(n);
    for (int i = 0; i < n; i++) {
        vector<char> row(m);
        vector<bool> bool_row(m, false);
        vector<int> int_row(m, 0);
        board[i] = row;
        visited[i] = bool_row;
        distance[i] = int_row;
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int a = 0, b = 0;
    vector<vector<char>> step = board;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A') {
                bfs(i, j, board, visited, distance, step);
            } else if (board[i][j] == 'B') {
                a = i, b = j;
            }
        }
    }

    int final_distance = distance[a][b];
    if (final_distance != 0) {
        cout << "YES\n";
        cout << final_distance << "\n";
        stack<char> path;
        get_path(a, b, path, step);;
        while (!path.empty()) {
            cout << path.top();
            path.pop();
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
