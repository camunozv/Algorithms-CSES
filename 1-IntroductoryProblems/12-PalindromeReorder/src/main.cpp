#include <bits/stdc++.h>
#define llui unsigned long int
using namespace std;

string palindromeReorder(string baseChain, llui n);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string characterChain;

    cin >> characterChain;

    cout << palindromeReorder(characterChain, (llui)characterChain.length());
    return 0;
}

string palindromeReorder(string baseChain, llui n)
{

    if (n % 2 == 0)
    {
        for(llui i = 0; i < (n/2); i++)
        {
            if (baseChain[i] != baseChain[n-1-i])
            {
                llui k = i + 1;
                while (k < (n-1-i) && baseChain[k] != baseChain[i])
                {
                    k++;
                }

                if (baseChain[k] == baseChain[i])
                {
                    char temporal = baseChain[n-1-i];
                    baseChain[n-1-i] = baseChain[k];
                    baseChain[k] = temporal;
                } else 
                {
                    baseChain = "NO SOLUTION";
                }
            }
        }
    }else
    {
        bool onlyOneInTheMiddle = false;
        for(llui i = 0; i < (n/2); i++)
        {
            if (baseChain[i] != baseChain[n-1-i])
            {
                llui k = i + 1;
                while (k < (n-1-i) && baseChain[k] != baseChain[i])
                {
                    k++;
                }

                if (baseChain[k] != baseChain[i] && !onlyOneInTheMiddle)
                {
                    char temporal = baseChain[(n/2)];
                    baseChain[(n/2)] = baseChain[k];
                    baseChain[k] = temporal;
                    onlyOneInTheMiddle = true;
                } else if (baseChain[k] == baseChain[i])
                {
                    char temporal = baseChain[n-1-i];
                    baseChain[n-1-i] = baseChain[k];
                    baseChain[k] = temporal;
                } else 
                {
                    baseChain = "NO SOLUTION";
                }
            }
        }
    }
    return baseChain;
}