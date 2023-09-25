#include <iostream>
using namespace std;

int main()
{

    long unsigned int n = 0;
    cin >> n;

    if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3" << endl;
    }
    else
    {
        long unsigned int permutation[n];

        long unsigned int i = 1;
        long unsigned int k = 1;
        long unsigned int m = n;
        while (i <= n)
        {
            permutation[i - 1] = k;
            permutation[i] = m;

            k++;
            m--;
            i += 2;
        }

        long unsigned int temporal = permutation[0];
        permutation[0] = permutation[n - 1];
        permutation[n - 1] = temporal;

        long unsigned int j = 0;
        while (j < n)
        {
            cout << permutation[j] << " ";
            j++;
        }
    }

    cout << " " << endl;

    return 0;
}