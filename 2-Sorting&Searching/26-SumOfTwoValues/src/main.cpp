#include <bits/stdc++.h>
 
using namespace std;
 
int binary_search(int n, vector<int> &v);
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
    int index_value_found = -1;
    int found_index_1 = 0;
 
    for (int j = 0; j < n; j++)
    {
        value_to_search = x - initial_array[j];
        index_value_found = binary_search(value_to_search, sorted_array);
        count++;
        if (index_value_found != -1)
        {
            found_index_1 = j;
            break;
        }
    }
 
    if (index_value_found == -1)
    {
        cout << "IMPOSSIBLE \n";
    }
    else
    {
        found_index_1++;
        index_value_found++;
        cout << found_index_1 << " " << index_value_found << "\n";
    }
 
    return 0;
}
 
int binary_search(int n, vector<int> &v)
{
    int index = v.size() / 2;
    int index2 = 0;
    bool found = false;
 
    while (index >= 1 && !found)
    {
        index2 = index / 2;
        if (v[index] == n)
        {
            found = true;
        }
        else if (n < v[index])
        {
            index -= index2;
        }
        else
        {
            index += index2;
        }
 
        index /= 2;
    }
 
    return found ? index : -1;
}
