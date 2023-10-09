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
            product /= 5;
        }
    }

    return zerosCounter;
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