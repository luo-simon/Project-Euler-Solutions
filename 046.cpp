// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

// 9 = 7 + 2×1^2
// 15 = 7 + 2×2^2
// 21 = 3 + 2×3^2
// 25 = 7 + 2×3^2
// 27 = 19 + 2x2^2
// 33 = 31 + 2×1^2

// It turns out that the conjecture was false.

// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    int limit = 2000000;
    bool sieve[limit] = { 0 };
    sieveOfErasthones(sieve, limit);

    for (int i = 9; ; i += 2){
        if (sieve[i]){
            bool valid = false;
            for (int p = 2; p < i; p++){
                if (!sieve[p]){
                    if (sqrt((i - p)/2) == (int)sqrt((i - p)/2)){
                        valid = true;
                        break;
                    } 
                }
            }
            if (!valid){
                cout << i << endl;
                return 0;
            }
        }
    }


    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}