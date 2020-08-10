// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include <cmath>
using namespace std;

int sumSquare(int n);
int squareSum(int n);

int main(){
    cout << squareSum(100) - sumSquare(100) << endl;
    return 0;
}

int sumSquare(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += pow(i, 2);
    }
    return sum;
}

int squareSum(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += i;
    }
    return round(pow(sum, 2));
}