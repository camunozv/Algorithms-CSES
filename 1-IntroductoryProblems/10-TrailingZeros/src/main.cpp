#include <iostream>
using namespace std;

int main()
{
    long unsigned int n = 0;
    cin >> n;

    cout << n / 5 << endl;
    cout << n % 5 << endl;
    cout << n / 2 << endl;

    long unsigned int product = 1;
    long unsigned int trailingZeros = 0;

    for (long unsigned int j = 1; j <= n; j++)
    {
        if (product % 5 == 0 || product % 2 == 0)
        {
            trailingZeros++;
            product = 1;
        }
        product *= j;
    }

    cout << trailingZeros << endl;

    return 0;
}