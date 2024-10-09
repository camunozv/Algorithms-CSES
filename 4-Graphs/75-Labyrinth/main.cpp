#include <bits/stdc++.h>

using namespace std;

void bfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited, vector<vector<int>> &distance) {
    queue<pair<int, int>> q;
    visited[i][j] = true;
    distance[i][j] = 0;
    pair<int, int> p;
    p.first = i, p.second = j;
    q.push(p);
    int n = board.size(), m = board[0].size();

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        if (node.first + 1 < n && !visited[node.first + 1][node.second] && board[node.first + 1][node.second] != '#') {
            pair<int, int> a = {node.first + 1, node.second};
            q.push(a);
            visited[node.first + 1][node.second] = true;
            distance[node.first + 1][node.second] = distance[node.first][node.second] + 1;
        }

        if (node.first - 1 >= 0 && !visited[node.first - 1][node.second] && board[node.first - 1][node.second] != '#') {
            pair<int, int> a = {node.first - 1, node.second};
            q.push(a);
            visited[node.first - 1][node.second] = true;
            distance[node.first - 1][node.second] = distance[node.first][node.second] + 1;
        }

        if (node.second - 1 >= 0 && !visited[node.first][node.second - 1] &&
            board[node.first][node.second - 1] != '#') {
            pair<int, int> a = {node.first, node.second - 1};
            q.push(a);
            visited[node.first][node.second - 1] = true;
            distance[node.first][node.second - 1] = distance[node.first][node.second] + 1;
        }

        if (node.second + 1 < m && !visited[node.first][node.second + 1] && board[node.first][node.second + 1] != '#') {
            pair<int, int> a = {node.first, node.second + 1};
            q.push(a);
            visited[node.first][node.second + 1] = true;
            distance[node.first][node.second + 1] = distance[node.first][node.second] + 1;
        }

    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int m = 0;

    cin >> n;
    cin >> m;

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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A') {
                // Throw the bfs
                bfs(i, j, board, visited, distance);
                break;
            }
        }
    }

    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'B') {
                a = i;
                b = j;
                break;
            }
        }
    }

    cout << distance[a][b] << "\n";
    return 0;
}
