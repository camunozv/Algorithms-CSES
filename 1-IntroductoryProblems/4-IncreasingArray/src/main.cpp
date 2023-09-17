#include <iostream>
using namespace std;

int main()
{
    int arrayLength = 0;
    cin >> arrayLength;

    int numbers[arrayLength];

    for (int i = 0; i < arrayLength; i++)
    {
        cin >> numbers[i];
    }

    long int moves = 0;

    for (int j = 1; j < arrayLength; j++)
    {
        int a = numbers[j];
        int b = numbers[j - 1];
        if (a < b)
        {
            moves += b - a;
            numbers[j] = b;
        }
    }

    cout << moves << endl;
    return 0;
}