#include <iostream>
using namespace std;

int main()
{

    string DNAchain;
    string DNAsubchain;
    cin >> DNAchain;

    // 1. create the candidate to the greatest subchain.
    int i = 0;
    while (i < DNAchain.length() && DNAchain[i] == DNAchain[i + 1])
    {
        DNAsubchain += DNAchain[i];
        i++;
    }

    int currentSize = i; // current length of the candidate to greatest chain
    
    // 2. Find the greatest subchain
    
    cout << currentSize << endl;

    return 0;
}