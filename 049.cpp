// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
// (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
// exhibiting this property, but there is one other 4-digit increasing sequence.

// What 12-digit number do you form by concatenating the three terms in this sequence?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    bool sieve[10000];
    sieveOfErasthones(sieve, 10000);

    for (int i = 1001; i < 3340; i += 2){
        if (sieve[i] == 1)
            continue;

        bool digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int num = i;
        while (num != 0){
            digits[(num % 10)] = true;
            num /= 10;
        }

        bool ok = true;
        for (int n = i; n < 10000; n += 3330){
            if (sieve[n] == 1){
                ok = false;
                break;
            }
            num = n;
            while (num != 0){
                if (digits[(num % 10)] == false){
                    ok = false;
                    break;
                }
                num /= 10;
            }
            if (!ok) break;
        }
        if (ok){
            cout << i << i + 3330 << i + 6660 << endl;
        };
    }	
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}