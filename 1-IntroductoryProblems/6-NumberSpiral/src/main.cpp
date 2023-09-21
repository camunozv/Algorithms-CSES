#include <iostream>
using namespace std;

int main()
{
    unsigned long int searchTimes = 0;
    cin >> searchTimes;
    unsigned long int resultArray[searchTimes];

    unsigned long int row = 0;
    unsigned long int column = 0;

    unsigned long int i = 0;
    while (i < searchTimes)
    {
        cin >> row;
        cin >> column;

        unsigned long int squareSize = (row > column) ? row * row : column * column;

        unsigned long int number = 0;
        unsigned long int searchInterval = 0;

        if (squareSize % 2 == 0)
        {
            if (row > column)
            {
                searchInterval = squareSize;
                number = searchInterval - column + 1;
            }
            else
            {
                searchInterval = squareSize - ((2 * column) - 2);
                number = searchInterval + row - 1;
            }
        }
        else
        {
            if (row > column)
            {
                searchInterval = squareSize - ((2 * row) - 2);
                number = searchInterval + column - 1;
            }
            else
            {
                searchInterval = squareSize;
                number = searchInterval - row + 1;
            }
        }

        resultArray[i] = number;
        i++;
    }

    for (unsigned long int i = 0; i < searchTimes; i++)
    {
        cout << resultArray[i] << endl;
    }

    return 0;
}