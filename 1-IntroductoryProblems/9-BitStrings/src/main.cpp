#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    long unsigned int modulo = pow(10, 9) + 7;
    long unsigned int n = 0;
    cin >> n;

    long unsigned int result = 1;

    for (long unsigned int i = 0; i < n; i++)
    {
        result *= 2;
        result = result % modulo;
    }

    cout << result << endl;

    return 0;
}