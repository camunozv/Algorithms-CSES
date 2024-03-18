#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Now we are going to use sorting to speed up the algorithm.
    // I is also important to note, thath eventhough c++ allows us to use
    // variable size arrays, that doesn't makes part of the c++ standard
    // that is why we should use vectors for the same purpose

    int n = 0;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    sort(array.begin(), array.end());

    int count = 1;
    for (int i = 0; i < (int) array.size() - 1; i++)
    {
        if (array[i] != array[i+1])
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}