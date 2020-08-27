// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
// For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    // Maximum pandigital number is 987654321
    
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}