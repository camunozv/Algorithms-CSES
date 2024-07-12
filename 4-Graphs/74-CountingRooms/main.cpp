#include <bits/stdc++.h>

using namespace std;

void dfs(int i, int j, int &room);
bool check(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int m = 0;

    cin >> n;
    cin >> m;

    vector<vector<char>> room_board(n);
    vector<vector<bool>> visited(n);

    for (int i = 0; i < n; i++) {
        vector<char> row(m);
        vector<bool> vis_rows(m);

        room_board[i] = row;
        visited[i] = vis_rows;

        for (int j = 0; j < m; j++) {
            cin >> room_board[i][j];
            visited[i][j] = false;
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < m; j++) {

        }
    }
    return 0;
}

void dfs(int i, int j, int &room, vector<vector<char>> &board, vector<vector<bool>> &visited) {

    if (visited[i][j]) {
        return;
    } else {
        visited[i][j] = true;
        if (check(i, j + 1, board, visited)) {
            dfs(i, j + 1, room, board, visited);

        } else if (check(i + 1, j, board, visited)) {
            dfs(i + 1, j, room, board, visited);

        } else if (check(i, j - 1, board, visited)) {
            dfs(i, j - 1, room, board, visited);

        } else if (check(i - 1, j, board, visited)) {
            dfs(i - 1, j, room, board, visited);
        } else {
            room++;
        }
    }

}

bool check(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited) {

    bool result = true;
    if (board[i][j] == '#' || visited[i][j]) {
        result = false;
    }

    return result;
}