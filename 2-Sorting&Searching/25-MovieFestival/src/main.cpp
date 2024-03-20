#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].second;
        cin >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    
    int count = 0;
    pair<int, int> movie;
    for (int i = 0; i < n; i++)
    {
        movie = movies[i];
        if (movie.first > movies[i + 1].second)
        {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}