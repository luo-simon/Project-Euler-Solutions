// Take the number 192 and multiply it by each of 1, 2, and 3:

// 192 × 1 = 192
// 192 × 2 = 384
// 192 × 3 = 576

// By concatenating each product we get the 1 to 9 pandigital, 192384576.
// We will call 192384576 the concatenated product of 192 and (1,2,3)

// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
// giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the
// concatenated product of an integer with (1,2, ... , n) where n > 1?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();
    
    string largest;
    // Maximum number is 9999, as 10000's concatenated product would exceed 9 digits.
    for (int i = 0; i <= 9999; i++){
        string str = to_string(i);
        int n = 1;
        while (str.length() < 9){
            n++;
            str += to_string(i * n);
        }
        if (isPandigital(str, 9))
            largest = str;
    }
    cout << largest << endl;
    
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}