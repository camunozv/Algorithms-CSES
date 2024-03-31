#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0; // amount of sticks
    cin >> n;

    vector<int> stick_lengths(n);

    for (int i = 0; i < n; i++)
        cin >> stick_lengths[i];

    // Genral algorithm idea: (bce its late and i want to go to sleep)

    // Grab the greatest possible common length i.e the longest stick
    // check how much would it cost to make all the sticks of that length
    // then with binary search try to improve the cost by bisecting the length
    // of the biggest stick, do that until we approach to the minimum.
    
    return 0;
}