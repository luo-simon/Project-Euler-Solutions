// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number?

#include <iostream>
using namespace std;

int main(){
    int N = 200000;
    bool numbers[N] = {0};

    for (int prime = 2; prime < N; prime++){
        for (int i = 2 * prime; i < N; i += prime)
        {
            numbers[i] = 1;
        }
    }
    
    int count = 0;
    for (int i = 2; i < N; i++){
        if (numbers[i] == 0){
            count++;
            if (count == 10001){
                cout << i << endl;
            }   
        }
    }
    return 0;
}