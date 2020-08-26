// The number, 197, is called a circular prime because all rotations of the digits:
// 197, 971, and 719, are themselves prime.

// There are thirteen such primes below 100:
// 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

// How many circular primes are there below one million?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    int sieveSize = 1000001;
    bool sieve[sieveSize] = { 0 };
    sieveOfErasthones(sieve, sieveSize);

    int count = 0;
    for (int i = 2; i < sieveSize; i++){
        if (sieve[i] == 0){
            int numRotations = digitsCount(i) - 1;
            int rotated = i;
            bool isCircularPrime = true;
            while (numRotations--){
                int units = rotated % 10;
                rotated /= 10;
                rotated += units * powNat(10, (digitsCount(i) - 1));
                if (sieve[rotated] == 1){
                    isCircularPrime = false;
                    break;
                }
            }
            if (isCircularPrime)
                count++;
        }
    }
    
    cout << count << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}