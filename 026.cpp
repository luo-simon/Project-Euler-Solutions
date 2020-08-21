// A unit fraction contains 1 in the numerator.
// The decimal representation of the unit fractions with denominators 2 to 10 are given:

// 1/2	= 	0.5
// 1/3	= 	0.(3)
// 1/4	= 	0.25
// 1/5	= 	0.2
// 1/6	= 	0.1(6)
// 1/7	= 	0.(142857)
// 1/8	= 	0.125
// 1/9	= 	0.(1)
// 1/10	= 	0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
// It can be seen that 1/7 has a 6-digit recurring cycle.

// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int reciprocalRecurringCycleLength(int divisor);

int main(){
    clock_t tStart = clock();
    int longestLength = 0;
    int d;
    int currentCycleLength;

    for (int i = 1; i <= 1000; i++){
        if (i <= longestLength)
            continue;
        currentCycleLength = reciprocalRecurringCycleLength(i);
        if (currentCycleLength > longestLength){
            longestLength = currentCycleLength;
            d = i;
        }
    }
    cout << d << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

int reciprocalRecurringCycleLength(int divisor){
    // Returns the length of the reccuring cycle for the ratio 1/divisor 

    vector<int> seenRemainders;
    seenRemainders.clear(); // Ensure vector is empty
    int dividend = 1;
    int remainder;

    while (true){
        dividend *= 10;
        remainder = dividend % divisor;
        if (remainder == 0)
            return 0;

        // Check remainder has already been seen (i.e. repeating)
        for (int i = 0; i < seenRemainders.size(); i++){
            if (seenRemainders[i] == remainder){
                return seenRemainders.size() - i;
            }       
        }
        seenRemainders.push_back(remainder);
        dividend = remainder;    
    }
    return 0;
}