#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    LLI apples = 0;

    cin >> apples;

    LLI weights[apples];

    for (LLI i = 0; i < apples; i++)
    {
        cin >> weights[i];
    }

    LLI totalWeight = 0;

    for (LLI i = 0; i < apples; i++)
    {
        totalWeight += weights[i];
    }

    cout << totalWeight % 2 << "\n";

    return 0;
}