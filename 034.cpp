// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

// Note: As 1! = 1 and 2! = 2 are not sums they are not included.

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

void cacheFactorials();
int sumFactorialDigits(int n);

int factorials[10];

int main(){
    clock_t tStart = clock();

    // Precompute and cache factorials
    cacheFactorials();

    // Maximum sum of factorials for 8 digit number is 9!+9!+... = 2,903,040,
    // which is only 7 digits long. So the limit is 7 digits (inclusive)
    // which has a maximum of 9!+9!...= 2540160
    int sum = 0;
    for (int i = 3; i <= 2540160; i++){
        if (sumFactorialDigits(i) == i){
            sum += i;
        }
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

void cacheFactorials(){
    for (int i = 0; i < 10; i++){
        factorials[i] = factorial(i);
    }
}

int sumFactorialDigits(int n){
    int sum = 0;
    while (n > 0){
        sum += factorials[n % 10];
        n /= 10;
    }
    return sum;
}