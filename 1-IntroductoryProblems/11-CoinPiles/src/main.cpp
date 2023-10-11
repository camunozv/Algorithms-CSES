#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long testCases;
    cin >> testCases;

    long int B = 0;
    long int A = 0;
    long int solution1 = 0;
    long int solution2 = 0;
    while (testCases > 0)
    {
        pair<long, long> testCase;

        cin >> testCase.first;
        cin >> testCase.second;

        B = (testCase.first - (2 * testCase.second)) / -3;
        A = testCase.second - (2 * B);

        solution1 = (2 * A) + B;
        solution2 = (2 * B) + A;

        if (solution1 == testCase.first && solution2 == testCase.second)
        {
            if (A >= 0 && B >= 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "NO\n";
        }

        testCases--;
    }

    return 0;
}