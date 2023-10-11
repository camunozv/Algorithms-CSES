#include <bits/stdc++.h>
using namespace std;

bool isMultipleOf3(long number1, long number2);
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);

    long testCases;
    cin >> testCases;

    while (testCases > 0)
    {
        pair<long, long> testCase;

        cin >> testCase.first;
        cin >> testCase.second;

        if (isMultipleOf3(testCase.first, testCase.second))
        {
            cout << "YAS\n";
        } else 
        {
            cout << "NO\n";
        }

        testCases--;
    }
    return 0;
}

bool isMultipleOf3(long number1, long number2)
{
    long sum = number1 + number2;
    return sum % 3 == 0;
}