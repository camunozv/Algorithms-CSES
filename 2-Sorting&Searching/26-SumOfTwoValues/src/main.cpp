#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();

    int n = 0;
    cin >> n;

    int x = 0;
    cin >> x;

    vector<int> initial_array(n);
    vector<int> sorted_array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> initial_array[i];
        sorted_array[i] = initial_array[i];
    }

    sort(sorted_array.begin(), sorted_array.end());

    int count = 0;
    int value_to_search = 0;
    int found_index_1 = 0;
    int value_found = 0;

    for (int j = 0; j < n; j++)
    {
        value_to_search = x - initial_array[j];
        auto iterator_value_found = lower_bound(sorted_array.begin(), sorted_array.end(), value_to_search);
        if (iterator_value_found == sorted_array.end() || *(iterator_value_found) != value_to_search)
        {
            count++;
            continue;
        }
        else
        {
            found_index_1 = j;
            value_found = *(iterator_value_found);
            break;
        }
    }

    if (count == n)
    {
        cout << "IMPOSSIBLE \n";
    }
    else
    {
        found_index_1++;
        int i = 0;
        while (initial_array[i] != value_found)
        {
            i++;
        }
        i++;
        cout << found_index_1 << " " << i << "\n";
    }

    return 0;
}
