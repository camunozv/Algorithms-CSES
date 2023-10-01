#include <iostream>
using namespace std;

bool checkIfSolution(long unsigned int k);
int main()
{
    long unsigned int n = 0;
    cin >> n;

    bool isFactible = checkIfSolution(n);

    if (n == 3)
    {
        cout << "YES" << endl;
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "2" << endl;
        cout << "2 1" << endl;
    }
    else if (isFactible)
    {
        cout << "YES" << endl;

        // get the sum we want to reach
        long unsigned int setSum = ((n) * (n + 1)) / 4;

        // create array where we want to save the combination
        long unsigned int combination[(n / 2) + 1] = {0};

        // cycle which finds out pairs, first and last element pairs.
        long unsigned int i = 1;
        long unsigned int superior = n;
        long unsigned int inferior = 1;

        long unsigned int sum = 0;
        long unsigned int counter = 0;

        while (sum < setSum)
        {
            if (sum != setSum)
            {
                sum += superior;
                combination[i - 1] = superior;
                counter++;
            }

            if (sum != setSum)
            {
                sum += inferior;
                combination[i] = inferior;
                counter++;
            }

            superior--;
            inferior++;
            i += 2;
        }

        long unsigned int j = 0;
        cout << counter << endl;

        while (j < counter)
        {
            cout << combination[j] << " ";
            j++;
        }

        cout << " " << endl;
        cout << n - counter << endl;

        long unsigned int a = combination[counter - 1] < combination[counter - 2] ? combination[counter - 1] : combination[counter - 2];
        long unsigned int b = combination[counter - 1] > combination[counter - 2] ? combination[counter - 1] : combination[counter - 2];

        if (b < a)
        {
            while (b < a - 1)
            {
                b++;
                cout << b << " ";
            }
        }
        else
        {
            while (a < b - 1)
            {
                a++;
                cout << a << " ";
            }
        }
        cout << " " << endl;
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