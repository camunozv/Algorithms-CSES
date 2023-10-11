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

        cin >> testCase.first;  // x
        cin >> testCase.second; // y

        B = (testCase.first - (2 * testCase.second)) / -3;
        A = testCase.second - (2 * B);
        
        solution1 = (2 * A) + B;
        solution2 = (2 * B) + A;

        cout << solution1 << "\n";
        cout << solution2 << "\n";

        cout << A << "\n";
        cout << B << "\n";

        if (solution1 == testCase.first && solution2 == testCase.second)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        testCases--;
    }

    return 0;
}