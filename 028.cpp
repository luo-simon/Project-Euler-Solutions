// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13

// It can be verified that the sum of the numbers on the diagonals is 101.

// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

#include <iostream>
#include <time.h>

using namespace std;

int main(){
    clock_t tStart = clock();

    // nth term for sequence of numbers from centre (1) to:
    // bottom right: 4n^2 - 10n + 7
    // bottom left: 4n^2 - 8n + 5
    // top left: 4n^2 - 6n + 3
    // top right: (2n - 1)^2
    // number of terms for each sequence in a 1001x1001 grid will be (1001+1)/2 = 501
    
    int spiralSize = 1001;
    int terms = (spiralSize+1)/2;
    int sum = 1; // 1 in centre

    for (int n = 2; n <= terms; n++){
        // This could be simplified into one expression,
        // but I think it is clearer to display each diagonal
        sum += 4*n*n - 10*n + 7;
        sum += 4*n*n - 8*n + 5;
        sum += 4*n*n - 6*n + 3;
        sum += (2*n -1) * (2*n - 1);
    }
    cout << sum << endl;

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}