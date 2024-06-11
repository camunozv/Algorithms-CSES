# include <bits/stdc++.h>

using namespace std;

int playlist(vector<int> a, int n);

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

int playlist(vector<int> a, int n) {

    int longest_songs = 0;

    unordered_set<int> longest_playlist;
    int value = 0;

    for (int i = 0; i < n; i++) {
        value = a[i];
        auto end_of = longest_playlist.end();
        if (longest_playlist.find(value) == end_of) {
            longest_playlist.insert(value);
        } else {
            if (longest_playlist.size() > longest_songs) {
                longest_songs = longest_playlist.size();
            }
            longest_playlist.clear();
        }
    }

    return longest_songs;
}