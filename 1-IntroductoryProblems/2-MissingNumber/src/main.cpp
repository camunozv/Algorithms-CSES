#include <iostream>
using namespace std;

int main()
{

    long int range = 0;
    cin >> range;

    int numbers[range - 1];
    for (int i = 0; i < (range - 1); i++)
    {
        cin >> numbers[i];
    }

    int expectedTotal = ((range * (range + 1)) / 2);
    int total = 0;
    for (int i = 0; i < (range - 1); i++)
    {
        total += numbers[i];
    }

    cout << expectedTotal - total << endl;

    return 0;
}