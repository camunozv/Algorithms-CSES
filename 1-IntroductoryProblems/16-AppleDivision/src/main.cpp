#include <bits/stdc++.h>

using namespace std;

int generate_subsets(int k, int n, int sum1, int sum2, vector<int> &elements);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> my_vector(n);

    for (int i = 0; i < n; i++)
        cin >> my_vector[i];

    cout << generate_subsets(0, n, 0, 0, my_vector) << "\n";
    return 0;
}

int generate_subsets(int k, int n, int sum1, int sum2, vector<int> &elements)
{
    int minimum = 0;
    if (k == n)
    {
        return abs(sum1 - sum2);
    }
    minimum = min(generate_subsets(k + 1, n, sum1 + elements[k], sum2, elements), generate_subsets(k + 1, n, sum1, sum2 + elements[k], elements));
    return minimum;
}
