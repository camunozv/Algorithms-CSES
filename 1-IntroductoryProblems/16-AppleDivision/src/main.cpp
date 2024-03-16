#include <bits/stdc++.h>

using namespace std;

void generate_subsets(int k, int n, vector<int> &elements, vector<bool> &included, vector<int> &set_weight);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 0;
    cin >> i;

    vector<int> my_vector(i);
    vector<bool> included(i);
    vector<int> set_weight;

    for (int j = 0; j < i; j++)
        cin >> my_vector[j];

    generate_subsets(0, my_vector.size(), my_vector, included, set_weight);

    int current_set = 0;
    int amount_sets = set_weight.size();
    int difference = 0;
    int best = pow(10, 9);

    for(int i = 0; i < amount_sets; i++)
    {
        current_set = set_weight[i];

        for(int j = 0; j < amount_sets; j++)
        {
            if (current_set == set_weight[j]) continue;

            difference = abs(current_set - set_weight[j]);
            best = min(difference, best);
        }
    }
    
    cout << best << "\n";

    return 0;
}

void generate_subsets(int k, int n, vector<int> &elements, vector<bool> &included, vector<int> &set_weight)
{
    if (k == n)
    {
        int set_sum;
        for(int i = 0; i < n; i++)
        {
            if (included[i] == 1)
            {
                set_sum += elements[i];
            }
        }
        set_weight.push_back(set_sum);
        set_sum = 0;

    } else 
    {
        included[k] = 1;
        generate_subsets(k + 1, n, elements, included, set_weight);
        included[k] = 0;
        generate_subsets(k + 1, n, elements, included, set_weight);
    }
}