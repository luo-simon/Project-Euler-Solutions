// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
// For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
// which means that 28 is a perfect number.

// A number n is called deficient if the sum of its proper divisors is less than n and
// it is called abundant if this sum exceeds n.

// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
// the smallest number that can be written as the sum of two abundant numbers is 24. 
// By mathematical analysis, it can be shown that all integers greater than 28123
// can be written as the sum of two abundant numbers. 
// However, this upper limit cannot be reduced any further by analysis even though
// it is known that the greatest number that cannot be expressed as the sum of two 
//abundant numbers is less than this limit.

// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <iostream>
#include <cmath>
#include <set>
#include <time.h>

using namespace std;


bool hasAbundantSum(int n);
int sumProperDivisors(int n);

set<int> abundantNumbers;

int main(){
    clock_t tStart = clock();

    for (int i = 1; i <= 28123; i++){
        if (sumProperDivisors(i) > i){
            abundantNumbers.insert(i);
        }
    }

    int sum = 0;
    for (int i = 1; i <= 28123; i++){
        if (!hasAbundantSum(i)){
            sum += i;
        }
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

bool hasAbundantSum(int n){
    for (auto abundantNumber : abundantNumbers){
        if (abundantNumber > n){
            return false;
        }
        if (abundantNumbers.count(n - abundantNumber) == 0){
            continue;
        }
        return true;
    }
    return false;
}

int sumProperDivisors(int n){
    /* Sum of proper divisors of n */
    int sum = 1;
    int root = sqrt(n);

    for (int i = 2; i <= root; i++){
        if (n % i == 0){
            sum += i;
            sum += n/i;
        }
    }

    if (n == root * root){
        sum -= root;
    }

    return sum;
}