#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    cin >> i;

    vector<int> my_vector(i);

    for (int j = 0; j < i; j++)
        cin >> my_vector[j];

    int total_weight = 0;

    for (int k = 0; k < i; k++)
        total_weight += my_vector[k];

    int index = 0;
    int best_difference = total_weight;
    int init_value = 0;

    int sum = 0;
    int difference_2 = 0;
    for (int r = 0; r < i; r++)
    {
        for (int n = 0; n < i; n++)
        {

            init_value = sum;
            init_value += my_vector[n];

            difference_2 = total_weight - init_value;

            if (difference_2 < best_difference)
            {
                best_difference = difference_2;
                index = n;
            }
        }
        sum += my_vector[index];
        total_weight -= sum;
        my_vector[index] = 0;
    }

    int main_difference = sum - total_weight;
    cout << main_difference << "\n";
    cout << total_weight << " " << sum << "\n";

    return 0;
}