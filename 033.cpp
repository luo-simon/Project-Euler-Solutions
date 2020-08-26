// The fraction 49/98 is a curious fraction,
// as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
// which is correct, is obtained by cancelling the 9s.

// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

// There are exactly four non-trivial examples of this type of fraction,
// less than one in value, and containing two digits in the numerator and denominator.

// If the product of these four fractions is given in its lowest common terms,
// find the value of the denominator.

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();

    int productNumerator = 1;
    int productDenominator = 1;
    
    for (int d = 10; d < 100; d++){
        for (int n = 10; n < d; n++){
            for (int i = 1; i < 10; i++){
                int nUnits = n % 10;
                int nTens = n / 10;
                int dUnits = d % 10;
                int dTens = d / 10;
                if (dTens == i && nUnits == i && (float)nTens/dUnits == (float)n/d){
                    productNumerator *= n;
                    productDenominator *= d;
                }
            }   
        }
    }

    cout << productDenominator / gcd(productNumerator, productDenominator) << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}