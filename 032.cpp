// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
// for example, the 5-digit number, 15234, is 1 through 5 pandigital.

// The product 7254 is unusual, as the identity, 39 × 186 = 7254,
// containing multiplicand, multiplier, and product is 1 through 9 pandigital.

// Find the sum of all products whose multiplicand/multiplier/product identity can be written as
// a 1 through 9 pandigital.

// HINT: Some products can be obtained in more than one way so be sure to
// only include it once in your sum.

#include <iostream>
#include <set>
#include <cmath>
#include <time.h>

using namespace std;

bool isPandigitalProduct(int n);

int main(){
    clock_t tStart = clock();
    
    int sum = 0;
    for (int i = 1; i <= 9999; i++){
        if (isPandigitalProduct(i))
            sum += i;
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

bool isPandigitalProduct(int n){
    for (int i = 1; i < sqrt(n); i++){
        if (n % i == 0){ 
            set<int> digits;
            string digitsStr = to_string(n) + to_string(i) + to_string(n/i);
            if (digitsStr.length() == 9){
                int sum = 0;
                for (int i = 0; i < 9; i++)
                    if (digitsStr[i] - '0' != 0)
                        digits.insert(digitsStr[i] - '0');
                if (digits.size() == 9)
                    return true;
            }
        }
    }
    return false;
}