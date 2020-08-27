// If p is the perimeter of a right angle triangle with integral length sides,
// {a,b,c}, there are exactly three solutions for p = 120.

// {20,48,52}, {24,45,51}, {30,40,50}

// For which value of p ≤ 1000, is the number of solutions maximised?

#include <iostream>
#include <time.h>
#include "useful.h"

using namespace std;

int main(){
    clock_t tStart = clock();

    int maxP = 0;
    int maxSols = 0;

    /* Brute force approach */
    // for (int p = 1; p <= 1000; p++){
    //     int solutions = 0;
    //     for (int a = 1; a <= p/2; a++){
    //         for (int b = a; b <= p/2; b++){
    //             float c = sqrt(powNat(a, 2) + powNat(b, 2));
    //             if (floor(c) == c && a + b + c == p)
    //                 solutions++;
    //         }
    //     }
    //     if (solutions > maxSols){
    //         maxP = p;
    //         maxSols = solutions;
    //     }
    // }
    
    /* Mathematical Approach */
    // There are two simultanenous equations:
    // a^2 + b^2 = c^2
    // a + b + c = p
    // Rearranging substituting, we get b = p(p-2a)/2(p-a)
    for (int p = 1; p <= 1000; p++){
        int solutions = 0;
        for (int a = 1; a <= p/2; a++){
            if (p*(p-2*a) % (2*(p-a)) == 0)
                solutions++;
            if (solutions > maxSols){
                maxP = p;
                maxSols = solutions;
            }
        }
    }
    cout << maxP << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}