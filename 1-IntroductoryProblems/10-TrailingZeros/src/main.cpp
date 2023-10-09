#include <bits/stdc++.h>
#define LLUI unsigned long long int
using namespace std;

int trailingZeros(LLUI nummer);
int main()
{
    LLUI n = 0;
    cin >> n;
    cout << trailingZeros(n) << "\n";
    return 0;
}

int trailingZeros(LLUI nummer)
{

    LLUI product = 1;
    int zerosCounter = 0;

    for (LLUI i = 5; i <= nummer; i += 5)
    {
        product = i;
        while (product % 5 == 0)
        {
            zerosCounter++;
            product = product / 5;
        }
    }

    return zerosCounter;
}