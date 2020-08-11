// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> sum(60, 0); // fills vector with 0 fifty-five times

    int count = 100;
    while (count--){
        string numberStr;
        cin >> numberStr;

        vector<int> digits;
        for (int i = numberStr.length() - 1; i >= 0 ; i--){
            digits.push_back(numberStr[i] - '0');
        }
        digits.resize(sum.size(), 0);

        for (int i = 0; i < digits.size(); i++){
            sum[i] += digits[i];
            if (sum[i] >= 10){
                sum[i+1]++;
                sum[i] -= 10;
            }
        }
    }

    auto i = sum.rbegin();
    while (*i == 0){
        i++;
    }

    int digitsToPrint = 10;
    while (digitsToPrint-- > 0){
        cout << *i++;
    }

    return 0;
}