#include <iostream>

using namespace std;

int main() {

    string DNAchain;
    cin >> DNAchain;

    // 1. count the number of words
                                int i = 0;
    int wordCounter = 0;
    while (i < (int) DNAchain.length()) {
        if (DNAchain[i] != DNAchain[i + 1]) {
            wordCounter++;
        }
        i++;
    }

    // 2. get the length of the words.
    int j = 0;
    int k = 0; // length per word
    int n = 0; // index of the words length array
    int wordsLength[wordCounter];
    while (j < (int) DNAchain.length()) {
        if (DNAchain[j] == DNAchain[j + 1]) {
            k++; // counts length of a word - 1
        } else {
            k++;                // we have to count the last character
            wordsLength[n] = k; // save the length of that word
            k = 0;              // reset the length counter
            n++;                // move the index of the length of the words array, for waiting for the next word
        }
        j++;
    }

    // 3. get the length of the greatest subchain
    int p = 1;
    int maxLength = wordsLength[0];
    while (p < wordCounter) {
        int wordLength = wordsLength[p];
        if (wordLength > maxLength) {
            maxLength = wordLength;
        }
        p++;
    }

    cout << maxLength << endl;
    return 0;
}
