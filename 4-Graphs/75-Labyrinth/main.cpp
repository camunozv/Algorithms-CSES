#include <bits/stdc++.h>

using namespace std;

void
solve(int i, int j, int &n, int &m, vector<vector<char>> &board, queue<tuple<int, int, char>> &the_queue, string &path);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    cin >> m;

    vector<vector<char>> labyrinth(n);

    for (int i = 0; i < n; i++) {
        vector<char> line(m);
        for (int j = 0; j < m; j++) {
            cin >> line[j];
        }
        labyrinth[i] = line;
    }

    int i1 = 0;
    int j1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') {
                i = i1;
                j = j1;
            }
        }
    }

    queue<tuple<int, int, char>> my_queue;

    string path;

    solve(i1, j1, n, m, labyrinth, my_queue, path);

    return 0;
}

void
solve(int i, int j, int &n, int &m, vector<vector<char>> &board, queue<tuple<int, int, char>> &the_queue,
      string &path) {

    tuple<int, int, char> pos_A = make_tuple(i, j, 00);
    the_queue.push(pos_A);

    while (!the_queue.empty() && board[i][j] != 'B') {
        tuple<int, int, char> front = the_queue.front();

        i = get<0>(front);
        j = get<1>(front);
        path += get<2>(front);

        if (i + 1 < n && board[i + 1][j] != '#') { // down
            tuple<int, int, char> pos = make_tuple(i + 1, j, 'D');
            the_queue.push(pos);
        }

        if (i - 1 >= 0 && board[i - 1][j] != '#') { // up
            tuple<int, int, char> pos = make_tuple(i - 1, j, 'U');
            the_queue.push(pos);
        }

        if (j + 1 < m && board[i][j + 1] != '#') { // right
            tuple<int, int, char> pos = make_tuple(i, j + 1, 'R');
            the_queue.push(pos);
        }

        if (j - 1 >= 0 && board[i][j - 1] != '#') { // left
            tuple<int, int, char> pos = make_tuple(i, j - 1, 'L');
            the_queue.push(pos);
        }
        the_queue.pop();
    }

    if (the_queue.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}