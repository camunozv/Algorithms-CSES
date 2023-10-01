#include <iostream>
using namespace std;

bool checkIfSolution(long unsigned int k);
int main()
{
    long unsigned int n = 0;
    cin >> n;

    bool isFactible = checkIfSolution(n);

    if (isFactible)
    {
        cout << "YES" << endl;

        // create array of numbers
        long unsigned int array[n];
        for (long unsigned int i = 0; i < n; i++)
        {
            array[i] = i + 1;
        };

        // get the sum we want to reach
        long unsigned int setSum = ((n) * (n + 1)) / 4;

        // create array where we want to save the combination
        long unsigned int combination[n];

        // cycle which finds out pairs, first and last element pairs.
        long unsigned int a = 0;
        long unsigned int b = n - 1;
        long unsigned int i = 1;
        long unsigned int superior = array[b];
        long unsigned int inferior = array[a];

        long unsigned int sum = 0;

        while (sum < setSum)
        {
            if (sum != setSum)
            {
                sum += superior;
                combination[i - 1] = superior;
            }

            if (sum != setSum)
            {
                sum += inferior;
                combination[i] = inferior;
            }

            b--;
            a++;
            superior = array[b];
            inferior = array[a];
            i += 2;
        }

        long unsigned int j = 0;
        cout << i - 1 << endl;
        while (j < i)
        {
            cout << combination[j] << " ";
            j++;
        }

        long unsigned int l = array[i - 1] - 2;
        // long unsigned int k = array[i - 2] - 2;

        while (l < n)
        {
            combination[l] = array[l];
            l++;
        }
        cout << "" << endl;
        while (i < n)
        {
            cout << combination[i] << " ";
            i++;
        }

        cout << " " << endl;
        cout << n - i + 1 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

bool checkIfSolution(long unsigned int k)
{
    long unsigned int gaussSum = ((k) * (k + 1)) / 2;
    return gaussSum % 2 == 0;
}