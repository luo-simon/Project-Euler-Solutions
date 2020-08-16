// Using names.txt (right click and 'Save Link/Target As...'),
// a 46K text file containing over five-thousand first names, 
// begin by sorting it into alphabetical order. 
// Then working out the alphabetical value for each name, 
// multiply this value by its alphabetical position in the list to obtain a name score.

// For example, when the list is sorted into alphabetical order, COLIN, 
// which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. 
// So, COLIN would obtain a score of 938 × 53 = 49714.

// What is the total of all the name scores in the file?

#include <iostream>
#include <fstream>
#include <set>
#include <time.h>

using namespace std;

int nameScore(string name);

int main(){
    clock_t tStart = clock();

    set<string> names; // A set is always sorted
    
    // Opening file
    ifstream inFile;
    inFile.open("p022_names.txt");
    if (!inFile){
        cout << "Unable to open file";
        exit(1);
    }

    // Reading file and inserting into set
    char c;
    string name;
    while (inFile >> c){
        if (c == '"'){
            continue;
        } else if (c == ','){
            names.insert(name);
            name = "";
        } else {
            name += c;
        }
    }
    names.insert(name); // Adds final name

    // Close file
    inFile.close();

    // Evaluate scores
    int position = 1;
    int sum = 0;
    for (string name : names){
        sum += nameScore(name) * position;
        position++;
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int nameScore(string name){
    int sum = 0;
    for (char c : name){
        sum += c - 'A' + 1;
    }
    return sum;
}