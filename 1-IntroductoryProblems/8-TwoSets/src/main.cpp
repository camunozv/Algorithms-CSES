#include <iostream>
using namespace std;

bool checkIfSolution(int k);
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
        long unsigned int combinationArrayLength = ((n) / 2) + 1;
        long unsigned int combination[combinationArrayLength];

        // cycle which finds out pairs, first and last element pairs.
        long unsigned int a = 0;
        long unsigned int b = n - 1;
        long unsigned int pairSum = array[a] + array[b];
        long unsigned int i = 0;

        do
        {
            setSum -= pairSum;             // subtract the first pair
            combination[i] = array[a];     // save minor member of the pair
            combination[i + 1] = array[b]; // save greatest member of the pair
            array[a] = -1;                 // cross the members of the pair
            array[b] = -1;
            a++; // prepare for selecting the next pairs
            b--;
            pairSum = array[a] + array[b]; // update pair sum with the new indexes
            i += 2;                        // prepare the space for the new data in the combination array

        } while (setSum > pairSum);

        if (setSum != 0)
        {
            combination[i] = setSum;
        }

        for (long unsigned int r = 0; r < combinationArrayLength; r++)
        {
            cout << combination[r] << " ";
        }

        cout << " " << endl;

        for(long unsigned int v = 0; v < n; v++)
        {
            if (array[v] != -1)
            {
                cout << array[v] << " ";
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

bool checkIfSolution(int k)
{
    int gaussSum = ((k) * (k + 1)) / 2;
    cout << gaussSum << endl;
    return gaussSum % 2 == 0;
}