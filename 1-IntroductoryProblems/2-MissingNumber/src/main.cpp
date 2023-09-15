#include <iostream>
using namespace std;

int main()
{

    int numberOfElements = 0;
    cin >> numberOfElements;

    int numbers[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < numberOfElements; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << " " << endl;
    return 0;
}