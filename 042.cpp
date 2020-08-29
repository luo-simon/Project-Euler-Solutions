// The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

// By converting each letter in a word to a number corresponding to its alphabetical position
// and adding these values we form a word value.
// For example, the word value for SKY is 19 + 11 + 25 = 55 = t10.
// If the word value is a triangle number then we shall call the word a triangle word.

// Using words.txt (right click and 'Save Link/Target As...'),
// a 16K text file containing nearly two-thousand common English words,
// how many are triangle words?

#include <iostream>
#include <time.h>
#include <set>
#include <fstream>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    int count = 0;

    // Opening file
    ifstream inFile;
    inFile.open("p042_words.txt");
    if (!inFile){
        cout << "Unable to open file";
        exit(1);
    }

    // Reading file and inserting into set
    set<string> words;
    char c;
    string word;
    while (inFile >> c){
        if (c == '"'){
            continue;
        } else if (c == ','){
            words.insert(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.insert(word); // Adds final name

    // Close file
    inFile.close();

    for (auto word : words){
        int value = 0;
        for (auto c : word)
            value += c - 'A' + 1;
        if (isTriangular(value)){
            count++;
            cout << word << endl;
        }
    }

    cout << count << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}