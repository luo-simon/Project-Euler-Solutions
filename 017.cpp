// If the numbers 1 to 5 are written out in words: 
// one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
// how many letters would be used?

// NOTE: Do not count spaces or hyphens. 
// For example, 342 (three hundred and forty-two) contains 
// 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
// The use of "and" when writing out numbers is in compliance with British usage.

#include <iostream>
#include <time.h>

using namespace std;

int letters(int n);

int main(){
    clock_t tStart = clock();
    
    int letterCount = 0;
    for (int i = 1; i <= 1000; i++){
        letterCount += letters(i);
    }
    cout << letterCount << endl;

    printf("Time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int letters(int n){
    switch (n){
        case  0: return 0;
        case  1: return 3;
        case  2: return 3;
        case  3: return 5;
        case  4: return 4;
        case  5: return 4;
        case  6: return 3;
        case  7: return 5;
        case  8: return 5;
        case  9: return 4;
        case 10: return 3;
        case 11: return 6;
        case 12: return 6;
        case 13: return 8;
        case 14: return 8;
        case 15: return 7;
        case 16: return 7;
        case 17: return 9;
        case 18: return 8;
        case 19: return 8;
        default: break;
    }

    if (n >= 20 && n < 100){
        int units = n % 10;
        int tens = n / 10;

        switch (tens){
            case 2: return 6 + letters(units);
            case 3: return 6 + letters(units);
            case 4: return 5 + letters(units);
            case 5: return 5 + letters(units);
            case 6: return 5 + letters(units);
            case 7: return 7 + letters(units);
            case 8: return 6 + letters(units);
            case 9: return 6 + letters(units);
            default: break; 
        }
    }

    if (n >= 100 && n < 1000){
        int tensAndUnits = n % 100;
        int hundreds = n / 100;
        int tensAndUnitsLetterCount = letters(tensAndUnits);
        if (tensAndUnitsLetterCount == 0){
            return letters(hundreds) + /*hundred*/ 7;
        } else {
            return letters(hundreds) + /*hundred and*/ 10 + letters(tensAndUnits);
        }
    }

    if (n == 1000){
        return 11; // one thousand
    }

    return 0;
}