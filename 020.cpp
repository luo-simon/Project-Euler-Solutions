// n! means n × (n − 1) × ... × 3 × 2 × 1

// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

// Find the sum of the digits in the number 100!

#include <iostream>
#include "InfInt.h" //https://sercantutar.github.io/infint/

using namespace std;

InfInt factorial(int n);
int digitsSum(InfInt n);

int main(){
    int n;
    cin >> n;
    cout << digitsSum(factorial(n)) << endl;
    return 0;
}

InfInt factorial(int n){
    InfInt factorial = 1;
    for (int i = 2; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}

int digitsSum(InfInt n){
    string numberStr = n.toString();
    int sum = 0;
    for (int i = 0; i < numberStr.length(); i++){
        sum += numberStr[i] - '0';
    }
    return sum;
}