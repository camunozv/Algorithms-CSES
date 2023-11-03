#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    int array[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(array[i]);
    }
    cout << s.size() << "\n";
    return 0;
}