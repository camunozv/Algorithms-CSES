# include <bits/stdc++.h>

# define li long int
using namespace std;

li playlist(vector<li> a, int n);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<li> song_sequence(n);

    for (int i = 0; i < n; i++) {
        cin >> song_sequence[i];
    }

    cout << playlist(song_sequence, n) + 1 << "\n";
    return 0;
}

li playlist(vector<li> a, int n) {

    li best = 0;

    map<li, li> sequence;
    li j = 0; // beginning

    for (li i = 0; i < n; i++) { // ending

        if (sequence.count(a[i])) {
            li temp = sequence[a[i]] + 1;
            if (temp >= j) {
                j = temp;
            }
        }

        sequence[a[i]] = i;

        if (i - j >= best) {
            best = i - j;
        }

    }

    return best;
}