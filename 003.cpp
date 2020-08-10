// The prime factors of 13195 are 5, 7, 13 and 29.

// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    unsigned long long int n = 600851475143;

    if (n % 2 ==0)
    {
        cout << "2\t";
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        while (n % i == 0){
            cout << i << "\t";
            n = n/i;
        }
    }    
    if (n > 2) cout << n << endl;

    return 0;
}