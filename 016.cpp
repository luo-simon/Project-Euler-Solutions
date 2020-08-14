// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 21000?

#include <iostream>
#include "InfInt.h" //https://sercantutar.github.io/infint/

using namespace std;

InfInt power(int base, int exponent);

int main(){
    InfInt number = power(2, 1000);
    string numberStr = number.toString();
    int sum = 0;
    for (int i = 0; i < numberStr.length(); i++){
        sum += numberStr[i] - '0';
    }
    cout << sum << endl;
    return 0;
}

InfInt power(int base, int exponent){
    InfInt result = 1;
    for (int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}