// The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

// (Please note that the palindromic number, in either base, may not include leading zeros.)

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    int sum = 0;
    for (int i = 0; i < 1000000; i++){
        if (isPalindrome(to_string(i)) && isPalindrome(toBinary(i)))
            sum += i;
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}