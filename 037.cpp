// The number 3797 has an interesting property.
// Being prime itself, it is possible to continuously remove digits from left to right,
// and remain prime at each stage: 3797, 797, 97, and 7.
// Similarly we can work from right to left: 3797, 379, 37, and 3.

// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    int limit = 2000000;
    bool sieve[limit] = { 0 };
    sieveOfErasthones(sieve, limit);

    int sum = 0;
    int count = 0;
    int i = 10;
    while (count < 11){
        if (sieve[i] == 0){
            bool isTruncPrime = true;
            int truncCount = digitsCount(i) - 1;
            int rightTrunc = i;
            int leftTrunc = i;
            while (truncCount--){
                rightTrunc /= 10;
                leftTrunc = leftTrunc % (powNat(10, truncCount + 1));
                if (sieve[rightTrunc] || sieve[leftTrunc]){
                    isTruncPrime = false;
                    break;
                }
            }
            if (isTruncPrime){
                sum += i;
                count++;
            }
        }
        i++;
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}