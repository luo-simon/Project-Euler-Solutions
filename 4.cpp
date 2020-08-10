// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(int n);

int main(){
    int max = 0;
    for (int i = 999; i > 99; i--)
    {
        for (int j = 999; j > 99; j--)
        {
            if (isPalindrome(i*j)){
                if (i*j > max){
                    max = i*j;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}

bool isPalindrome(int n){
    string str = to_string(n);
    int len = str.length();
    for (int i = 0; i <= floor(len/2); i++)
    {
        if (str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}