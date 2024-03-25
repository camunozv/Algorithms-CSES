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

    
    int count = 1;
    
    pair<int, int> movie_2 = movies[0];
    int last_endtime = movies[0].first;

    for (int i = 1; i < n; i++)
    {
        movie_2 = movies[i];

        if (movie_2.second >= last_endtime)
        {
            last_endtime = movie_2.first;
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}