// Header file written by Simon Luo, containing several useful functions, made for Project Euler problems.

#include <iostream>
#include <math.h>
#include <set>
#include <sstream>
using namespace std;

// Returns the greatest common divisor (using Euclid's algorithm)
// given that a >= b
int gcd(int a, int b) {
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

bool isPalindrome(string n){
    int len = n.length();
    for (int i = 0; i <= len/2; i++)
    {
        if (n[i] != n[len-1-i])
            return false;
    }
    return true;
}

// Returns n! as long as n! is under 8 bytes (18,446,744,073,709,551,615)
unsigned long long int factorial(int n){
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

// Returns sum of all digits in n
unsigned int digitsSum(int n){
    unsigned int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Returns the number of digits in n
int digitsCount(int n){
    int count = 0;
    while (n > 0){
        count++;
        n /= 10;
    }
    return count;
}

// Takes in boolean array (initialised to 0) and finds primes (via sieve)
// 1 means is not prime, 0 means is prime
void sieveOfErasthones(bool *sieve, int size){
    sieve[0] = 1;
    sieve[1] = 1;
    for (int p = 2; p < sqrt(size); p++){
        if (sieve[p] == 0){
            for (int i = p*p; i < size; i += p)
                sieve[i] = 1;
        }
    }
}

// Takes in set<unsigned int> and inserts primes up to limit
// Slightly different to sieveOfErasthones() function (slower)
void generatePrimes(set<unsigned int> &primes, unsigned int limit){
    primes.insert(2);
    for (int i = 3; i <= limit; i+= 2){
        bool isPrime = true;
        for (auto p : primes){
            if (p*p > i)
                break;
            if (i % p == 0){
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.insert(i);
    }
}

// Returns a to the power b,
// given that a and b are natural numbers
unsigned long long int powNat(int a, int b){
    if (a <= 0 || b <= 0){
        cout << "[!] powNat(a, b): Ensure a and b are natural numbers" << endl;
        return 0;
    }
    unsigned long long int result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    return result;
}

string toBinary(int n){
    string bStr;
    if (n < 0){
        cout << "[!] toBinary(n): Ensure n is not negative" << endl;
        return 0;
    }
    if (n == 0)
        return "0";
    while (n > 0){
        int r = n % 2;
        bStr += r + '0'; // Converts digit to ascii character
        n /= 2;
    }
    return bStr;
}

/* Old function for checking if number is pandigital */
// // Checks the string uses all of the digits 1 to n exactly once
// bool isPandigital(string s, int n){
//     set<int> digits;
//     if (s.length() == n){
//         for (int i = 0; i < n; i++)
//             if (s[i] - '0' != 0 && s[i] <= n)
//                 digits.insert(s[i] - '0');
//         if (digits.size() == n)
//             return true;
//     }
//     return false;
// }

bool isPandigital(unsigned long long int n, bool includeZero = false){
    bool digits[] = {0,0,0,0,0,0,0,0,0,0};
    int length = 0;
    while (n != 0){
        if (!includeZero && n % 10 == 0)
            return false;
        digits[(n % 10)] = true;
        n /= 10;
        length++;
    }
    if (length > 9 + includeZero) return false;
    for (int i = !includeZero; i <= length; i++)
        if (!digits[i]) return false;
    return true;
}

unsigned long long int toInteger(string str){
    unsigned long long int n;
    stringstream ss;
    ss << str;
    ss >> n;
    return n;
}

// Checks if prime by simple trial division
bool isPrime(unsigned int n){
    if (n % 2 == 0) return false;
    for (int i = 3; i*i < n; i+=2){
        if (n % i == 0) return false;
    }
    return true;
}

// Tests if number is a triangular number
// by finding the inverse of the nth term function 
// https://en.wikipedia.org/wiki/Triangular_number
bool isTriangular(unsigned int x){
    if (x < 0){
        cout << "[!] isTriangular(x): Ensure x > 0" << endl;
        return false;
    }
    double n = (sqrt(8*x + 1) - 1) / 2;
    return n == (int)n;
}

// Tests if number is a pentagonal number
// by finding the inverse of the nth term function 
// https://en.wikipedia.org/wiki/Pentagonal_number
bool isPentagonal(unsigned long long x){
    if (x < 0){
        cout << "[!] isPentagonal(x): Ensure x > 0" << endl;
        return false;
    }
    double n = (sqrt(24*x + 1) + 1.0) / 6.0;
    return n == (int)n;
}

// Tests if number is a hexagonal number
// by finding the inverse of the nth term function 
// https://en.wikipedia.org/wiki/Hexagonal_number
bool isHexagonal(unsigned int x){
    if (x < 0){
        cout << "[!] isHexagonal(x): Ensure x > 0" << endl;
        return false;
    }
    double n = (sqrt(8*x + 1) + 1) / 4;
    return n == (int)n;
}
