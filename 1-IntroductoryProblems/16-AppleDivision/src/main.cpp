#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll apple_division(int k, int n, ll sum1, ll sum2, vector<int> &elements);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    vector<int> my_vector(n);

    for (int i = 0; i < n; i++)
        cin >> my_vector[i];

    cout << apple_division(0, n, 0, 0, my_vector) << "\n";
    return 0;
}

ll apple_division(int k, int n, ll sum1, ll sum2, vector<int> &elements)
{
    if (k == n)
    {
        return abs(sum1 - sum2);
    }
    return min(apple_division(k + 1, n, sum1 + elements[k], sum2, elements), apple_division(k + 1, n, sum1, sum2 + elements[k], elements));
}
