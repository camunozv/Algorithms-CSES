#include <bits/stdc++.h>

using namespace std;

vector<stack<int>> grayCode(int n);
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<stack<int>> vectorOfStacks = grayCode(n);
    int size = vectorOfStacks.size();

    for (int i = 0; i < size; i++)
    {
        stack<int> stackToPrint = vectorOfStacks[i];

        while (!stackToPrint.empty())
        {
            cout << stackToPrint.top();
            stackToPrint.pop();
        }

        cout << "\n";
    }

    return 0;
}

vector<stack<int>> grayCode(int n)
{
    vector<stack<int>> returnVector;

    if (n == 1)
    {
        stack<int> zeros;
        stack<int> one;

        zeros.push(0);
        one.push(1);

        returnVector.push_back(zeros);
        returnVector.push_back(one);
    }
    else
    {
        returnVector = grayCode(n - 1);

        int s = returnVector.size();
        for (int i = 0; i < s; i++)
        {
            returnVector[i].push(0);
        }

        for (int i = s - 1; i >= 0; i--)
        {
            stack<int> reverse = returnVector[i];
            reverse.top() = 1;
            returnVector.push_back(reverse);
        }
    }

    return returnVector;
}