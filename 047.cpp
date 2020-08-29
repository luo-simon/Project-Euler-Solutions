// The first two consecutive numbers to have two distinct prime factors are:

// 14 = 2 × 7
// 15 = 3 × 5

// The first three consecutive numbers to have three distinct prime factors are:

// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.

// Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

#include <iostream>
#include <time.h>
#include <set>
#include "useful.h"

using namespace std;

const int limit = 100000;
bool sieve[limit] = { 0 };

int distinctPrimeFactors(int n);

int main(){
    clock_t tStart = clock();
    
    sieveOfErasthones(sieve, limit);
    int consecutive = 1;
    int n = 646;
    while (consecutive < 4){
        n++;
        if (distinctPrimeFactors(n) >= 4)
            consecutive++;
        else
            consecutive = 0;
    }
    cout << n - 3 << endl;
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int distinctPrimeFactors(int n){
    int count = 0;
    for (int p = 2; p <= n; p++){
        if (sieve[p] == 1)
            continue;
        bool primeFactor = false;
        while (n % p == 0){
            primeFactor = true;
            n /= p;
        }
        if (primeFactor){
            count++;
        }
        if (n == 1){
            return count;
        }
    }
    return count;
}