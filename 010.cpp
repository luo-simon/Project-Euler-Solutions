// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

// Find the sum of all the primes below two million.

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    bool numbers[2000001] = { 0 };
    for (int prime = 2; prime <= sqrt(2000001); prime++){
        if (numbers[prime] == 0){
            for (int i = prime*prime; i <= 2000001; i += prime){
             numbers[i] = 1;
            }
        }
    }
    unsigned long long int sum = 0;
    for (int i = 2; i <= 2000000; i++){
        if (numbers[i] == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}