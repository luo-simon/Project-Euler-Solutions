// Header file written by Simon Luo, containing several useful functions, made for Project Euler problems.

#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
    // Returns the greatest common divisor 
    // (using Euclid's algorithm)
    // given that a >= b

    if (a <= 0 || b <= 0){
        cout << "[!] gcd(a,b): Ensure that a and b are positive integers" << endl;
        return 0;
    }

    if (b > a)
        swap(a, b);

    int q = a / b;
    int r = a % b;
    
    if (r == 0)
        return b; 
    
    return gcd(b, r);
}

bool isPalindrome(int n){
    string str = to_string(n);
    int len = str.length();
    for (int i = 0; i <= len/2; i++)
    {
        if (str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}

unsigned long long int factorial(int n){
    // Returns n! as long as n! is under 8 bytes (18,446,744,073,709,551,615)

    if (n > 20){
        cout << "[!] factorial(n): n! exceeds limit (unsigned long long int)" << endl;
        return 0;
    }
    if (n < 0){
        cout << "[!] factorial(n): n must be greater or equal to 0" << endl;
    }

    unsigned long long int p = 1; // N.B. 0! = 1
    for (int i = 2; i <= n; i++)
        p *= i;
    return  p;
}

unsigned int digitsSum(int n){
    // Returns sum of all digits in n
    unsigned int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int digitsCount(int n){
    // Returns the number of digits in n
    int count = 0;
    while (n > 0){
        count++;
        n /= 10;
    }
    return count;
}

void sieveOfErasthones(bool *sieve, int size){
    // 1 means is not prime, 0 means is prime
    sieve[0] = 1;
    sieve[1] = 1;
    for (int prime = 2; prime < sqrt(size); prime++){
        if (sieve[prime] == 0){
            for (int i = prime*prime; i < size; i += prime)
                sieve[i] = 1;
        }
    }
}

unsigned long long int powNat(int a, int b){
    // Returns a to the power b,
    // given that a and b are natural numbers
    if (a <= 0 || b <= 0){
        cout << "[!] powNat(a, b): Ensure a and b are natural numbers" << endl;
        return 0;
    }
    unsigned long long int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    return result;
}
