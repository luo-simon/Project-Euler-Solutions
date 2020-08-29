// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
// For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <time.h>
#include <set>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();

    // Maximum pandigital number is 987654321
    // However a 9 digit pandigital number is divisible by 3 (9+8+..+1=45)
    //        an 8 digit pandigital number is divisible by 3 (8+7+..+1=36)
    // Therefore we can start from the maximum 7 digit pandigital number: 7654321

    for (int i = 7654321; i >= 0; i--){
        if (isPandigital(i) && isPrime(i)){
            cout << i << endl;
            printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
            return 0;
        }
    }
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}



