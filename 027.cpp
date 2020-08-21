// Euler discovered the remarkable quadratic formula:
// n^2 + n + 41
// It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39
// However, when n=40, 40^2+40+41=40(41)+41 is divisible by 41,
// and certainly when n=41, it is clearly divisible by 41.

// The incredible formula n^2-79n+1601 was discovered,
// which produces 80 primes for the consecutive values 0<=n<=79.
// The product of the coefficients, −79 and 1601, is −126479.

// Considering quadratics of the form:
// n^2+an+b, where |a| < 1000 and |b| <= 1000 

// where |n| is the modulus/absolute value of n

// Find the product of the coefficients a and b for the quadratic expression that
// produces the maximum number of primes for consecutive values of n, starting with n=0.

#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

bool sieve[2000001] = { 0 };

void sieveOfErasthones();

int main(){
    clock_t tStart = clock();
    
    sieveOfErasthones(); // Set up sieve

    int longestConsecutive = 0;
    int product;
    int n;
    for (int a = -999; a < 1000; a++){
        for (int b = -1000; b <= 1000; b++){
            n = 0;
            while (!sieve[n*n + a*n + b] && n*n + a*n + b > 0)
                n++;
            if (n > longestConsecutive){
                longestConsecutive = n;
                product = a * b;
            }
        }
    }
    cout << product << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

void sieveOfErasthones(){
    sieve[0] = 1;
    sieve[1] = 1;
    for (int prime = 2; prime <= sqrt(2000001); prime++){
        if (sieve[prime] == 0){
            for (int i = prime*prime; i <= 2000001; i += prime)
                sieve[i] = 1;
        }
    }
}