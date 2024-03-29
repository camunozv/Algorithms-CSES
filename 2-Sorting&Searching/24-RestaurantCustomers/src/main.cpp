#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size = 0;
    cin >> size;

    size *= 2;
    vector<pair<int, bool>> customer_times(size);

    for (int i = 0; i < size; i++)
    {
        cin >> customer_times[i].first;
        if (i % 2 == 0)
        {

            customer_times[i].second = true; // arrival == true
        }
        else
        {

            customer_times[i].second = false; // departure == false
        }
    }

    sort(customer_times.begin(), customer_times.end());

    int counter = 0;
    int best = 0;
    for (auto x : customer_times)
    {
        if (x.second == false)
        {
            counter--;
        }
        else
        {
            counter++;
        }

        if (counter > best)
        {
            best = counter;
        }
    }

    cout << best << "\n";
    return 0;
}