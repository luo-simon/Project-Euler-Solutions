// A permutation is an ordered arrangement of objects.
// For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
// If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:

// 012   021   102   120   201   210

// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int factorial(int n);

int main(){
    clock_t tStart = clock();

    vector<int> availableNumbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> nthPermutation;
    int remaining = 1000000;
    
    int N;
    for (int i = 0; i < 10; i++){
        N = availableNumbers.size();
        for (int i = 0; i < N; i++){
            if (factorial(N - 1) < remaining){
                remaining -= factorial(N - 1);
            } else {
                nthPermutation.push_back(availableNumbers[i]);
                availableNumbers.erase(availableNumbers.begin() + i);
                break;
            }
        }
    }

    for (int i = 0; i < nthPermutation.size(); i++){
        cout << nthPermutation[i];
    }
    cout << endl;
    
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int factorial(int n){
    int factorial = 1;
    for (int i = 2; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}