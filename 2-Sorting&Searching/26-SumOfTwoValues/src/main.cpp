#include <bits/stdc++.h>

using namespace std;

int binary_search_1(int x, vector<int> &v);
int binary_search_2(int x, vector<int> &v);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();

    int n = 0;
    cin >> n;

    int target = 0;
    cin >> target;

    vector<int> initial_array(n);
    vector<int> sorted_array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> initial_array[i];
        sorted_array[i] = initial_array[i];
    }

    sort(sorted_array.begin(), sorted_array.end());

    int value_1 = 0;
    int value_2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int possible = target - sorted_array[i];
        auto possible_found = lower_bound(sorted_array.begin() + i + 1, sorted_array.end(), possible);

        if (*(possible_found) != possible)
        {
            continue;
        }
        else
        {
            value_1 = possible;
            value_2 = sorted_array[i];
            break;
        }
    }

    if (value_1 + value_2 == target)
    {
        int i1 = 0;
        while (initial_array[i1] != value_1)
        {
            i1++;
        }

        int i2 = n - 1;
        while (initial_array[i2] != value_2)
        {
            i2--;
        }
        i1++;
        i2++;
        cout << i1 << " " << i2 << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE \n";
    }

    return 0;
}

int binary_search_1(int x, vector<int> &v)
{
    int inferior = 0;
    int superior = v.size() - 1;
    int k = 0;
    bool found = false;
    while (inferior <= superior && !found)
    {
        k = (superior + inferior) / 2;

        if (v[k] == x)
        {
            found = true;
        }
        else if (x < v[k])
        {
            superior = k - 1;
        }
        else
        {
            inferior = k + 1;
        }
    }
    return v[k] == x ? x : -1;
}

int binary_search_2(int x, vector<int> &v)
{
    int jump = 0;
    int size = v.size();
    int possible_increment = size / 2;
    while (possible_increment >= 1)
    {
        while (jump + possible_increment < size && v[jump + possible_increment] <= x) // jump is only incremented if conditions the element is in range
        {
            jump += possible_increment;
        }

        possible_increment /= 2;
    }

    return v[jump] == x ? v[jump] : -1;
}