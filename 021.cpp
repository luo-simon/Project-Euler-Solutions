// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

// Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int d(int n);

int main(){
    clock_t tStart = clock();

    int sum = 0;
    for (int a = 2; a < 10000; a++){
        if (d(d(a)) == a & d(a) != a){
            sum += a;
        }
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int d(int n){
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