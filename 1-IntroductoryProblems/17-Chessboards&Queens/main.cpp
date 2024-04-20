#include <bits/stdc++.h>

using namespace std;

void n_queen_problem(int &n, int row, int &count, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2,
                     vector<vector<char>> &board);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> board;

    for (int i = 0; i < 8; i++) {
        vector<char> row(8);
        board.push_back(row);
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    int n = 8;
    int count = 0;
    vector<bool> rows(n, true);
    vector<bool> diag1((2 * n) - 1, true);
    vector<bool> diag2((2 * n) - 1, true);

    n_queen_problem(n, 0, count, rows, diag1, diag2, board);
    cout << count << "\n";
    return 0;
}

void n_queen_problem(int &n, int row, int &count, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2,
                     vector<vector<char>> &board) {
    if (row == n) {
        count++;
    } else {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == '.' && cols[col] && diag1[row + col] &&
                diag2[row - col + n - 1]) {
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
                n_queen_problem(n, row + 1, count, cols, diag1, diag2, board);
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
            }
        }
    }
}
