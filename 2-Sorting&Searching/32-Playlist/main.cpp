# include <bits/stdc++.h>

using namespace std;

unsigned long int playlist(vector<int> a, int n);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> song_sequence(n);

    for (int i = 0; i < n; i++) {
        cin >> song_sequence[i];
    }

    cout << playlist(song_sequence, n) << "\n";
    return 0;
}

unsigned long int playlist(vector<int> a, int n) {

    map<int, int> sequence;
    unsigned long int best = 0;
    int value = 0;

    for (int i = 0; i < n; i++) {
        value = a[i];
        if (sequence.find(value) == sequence.end()) {
            sequence[value] = i;
        } else {
            i = sequence[value] + 1;

            if (sequence.size() > best) {
                best = sequence.size();
            }
            sequence.clear();
        }
    }

    return best;
}