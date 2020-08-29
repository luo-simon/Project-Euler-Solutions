// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

#include <iostream>
#include <time.h>
#include "useful.h"
#include "InfInt.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    InfInt sum = 0;
    for (int i = 1; i <= 1000; i++){
        InfInt term = 1;
        for (int j = 0; j < i; j++)
            term *= i;
        sum += term;
    }
    cout << sum.toString().substr(sum.numberOfDigits() - 10, 10) << endl;;
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}