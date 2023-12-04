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

    multiset<LLI> appleSet1;

    for(LLI i = 0; i < apples; i++)
    {
        appleSet1.insert(weights[i]);
    }

    cout << "\n";
    
    return 0;
}