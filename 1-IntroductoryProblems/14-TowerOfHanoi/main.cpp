#include <bits/stdc++.h>

using namespace std;

pair<int, int> tower_of_hanoi(int n, int sp, int sd, vector<pair<int, int>> &answer);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<pair<int, int>> movements;

    pair<int,int> store = tower_of_hanoi(n, 1, 3, movements);
    cout << movements.size() << "\n";

    for (auto mov: movements) {
        cout << mov.first << " " << mov.second << "\n";
    }

    return 0;
}

pair<int, int> tower_of_hanoi(int n, int sp, int sd, vector<pair<int, int>> &answer) {

    if (n == 1) {
        pair<int, int> last;
        last.first = sp;
        last.second = sd;
        return last;
    } else {
        int newSd = 0;
        for (int i = 1; i < 4; i++) {
            if (i != sp && i != sd) {
                newSd = i;
            }
        }
        pair<int, int> mov = tower_of_hanoi(n - 1, sp, newSd, answer);
        answer.push_back(mov);
        return mov;
    }
}