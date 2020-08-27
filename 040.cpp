// An irrational decimal fraction is created by concatenating the positive integers:

// 0.123456789101112131415161718192021...

// It can be seen that the 12th digit of the fractional part is 1.

// If dn represents the nth digit of the fractional part, find the value of the following expression.

// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    // d = 123456789 | 101112...99 | 100101102...999 | 1001...9999 | 10000...99999 ...
    // We can separate terms into groups by number of digits
    // 1-9: d1 to d9
    // 10-99: d10 to d(9 + 2*(99-9)) => d10 to d189
    // 100-999: ... => d190 to d2889
    // 1000-9999: d2890 to d38889
    // 10000-99999: d38890 to d488889
    // 100000-999999: d488890 to d5888889
    // Therefore, d1=1, d10=1, d100=(100-9)/2 + 9=5, d1000=(1000-189)/3 + 99=3 ...
    // d10,000 = 7; d100,000 = 2, d1,000,000=1

    cout << 1 * 1 * 5 * 3 * 7 * 2 * 1 << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}