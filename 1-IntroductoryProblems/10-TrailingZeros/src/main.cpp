#include <bits/stdc++.h>
#define LLUI unsigned long long int
#define LL long long
using namespace std;

int trailingZeros(LLUI nummer);
int trailingZerosGod(LLUI nummer);
int main()
{
    LLUI n = 0;
    cin >> n;
    cout << trailingZeros(n) << "\n";
    cout << trailingZerosGod(n) << "\n";

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
            product /= 5;
        }
    }

    return zerosCounter;
}

int trailingZerosGod(LLUI nummer)
{
    // We need a control variable, but is almost done, the trick is to use the function
    // log_5(5 * x);
    LL x = 1;
    LL r = 5;
    int z = 0;
    while (x <= nummer)
    {
        r = 5 * x;
        if (x % 5 != 0)
        {
            z++;
        }
        else
        {
            while (r % 5 == 0)
            {
                z++;
                r /= 5;
            }
        }
        x++;
    }

    return z;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod (int)(1e9+7)
// int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

// ll z=0,n;
// cin>>n;
// for(ll i=5;i<=n;i*=5) z+=n/i;
// cout<<(z);
// return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n, result = 0;
//     int power5 = 5;
//     cin >> n;
//     for (int i = 1; i <= 12; i++)
//     {
//         result += n / power5;
//         power5 *= 5;
//     }
//     cout << result << "\n";
// }