// Surprisingly there are only three numbers that can be written as
// the sum of fourth powers of their digits:

// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// As 1 = 1^4 is not a sum it is not included.

// The sum of these numbers is 1634 + 8208 + 9474 = 19316.

// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main(){
    clock_t tStart = clock();
    // The max number of digits is 6, as 7*9^5 is still a 6 digits number.
    // We can use 6*9^5 (354294) as a limit as this is the maximum value a 6 digit number can achieve.

    unsigned int sum = 0;
    for (int i = 2; i <= 354294; i++){
        string str = to_string(i);
        unsigned int digitsSum = 0;
        for (int j = 0; j < str.length(); j++)
            digitsSum += pow(str[j] - '0', 5);
        if (digitsSum == i)
            sum += i;
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}