#include <bits/stdc++.h>

using namespace std;

void tower_of_hanoi(int n, int sp, int sd, vector<pair<int, int>> &answer) ;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<pair<int, int>> movements;

    tower_of_hanoi(n, 1, 3, movements);
    cout << movements.size() << "\n";
    for (auto mov: movements) {
        cout << mov.first << " " << mov.second << "\n";
    }
    return 0;
}

void tower_of_hanoi(int n, int sp, int sd, vector<pair<int, int>> &answer) {
    if (n == 1){
        pair<int, int> last;
        last.first = sp;
        last.second = sd;
        answer.push_back(last);
    } else {
        int sd_star = 0;
        for (int i = 1; i < 4; i++){
            if (i != sp && i != sd){
                sd_star = i;
            }
        }
        tower_of_hanoi(n-1, sp, sd_star, answer);
        tower_of_hanoi(1, sp, sd, answer);
        tower_of_hanoi(n-1, sd_star, sd, answer);
    }
}