#include <iostream>
using namespace std;

int main()
{
    int searchTimes = 0;
    cin >> searchTimes;
    int resultArray[searchTimes];

    int i = 0;
    while (i < searchTimes)
    {
        int coordinates[2];
        cin >> coordinates[0]; // row position
        cin >> coordinates[1]; // column position

        int a = coordinates[0] * coordinates[0];
        int b = coordinates[1] * coordinates[1];

        int squareSize = (a > b) ? a : b;

        // Algorithm code here
        i++;
    }
    return 0;
}