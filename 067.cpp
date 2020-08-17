// By starting at the top of the triangle below and moving to adjacent numbers on the row below,
// the maximum total from top to bottom is 23.

// 3
// 7 4
// 2 4 6
// 8 5 9 3

// That is, 3 + 7 + 4 + 9 = 23.

// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
// a 15K text file containing a triangle with one-hundred rows.

// NOTE: This is a much more difficult version of Problem 18.
// It is not possible to try every route to solve this problem, as there are 299 altogether!
// If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all.
// There is an efficient algorithm to solve it. ;o)


/* This is the same solution I made for problem 18! */
#include <iostream>
#include <time.h>

using namespace std;

int main(){
	int rows = 100;
	// Getting user input (for triangle)
	int numbers[(rows * (rows+1)) / 2];
	for (int i = 0; i < (rows * (rows + 1)) / 2; i++){
		cin >> numbers[i];
	}

	// Timer to see execution time (unrelated to Euler problem)
	clock_t tStart = clock();

	// Setting triangle values to user input (and unused to 0)
	int triangle[rows][rows];
	for (int i = 0; i < rows; i++){
		for (int j = 0; j <= rows; j++){
			if (j <= i)
				triangle[i][j] = numbers[(i*(i+1))/2 + j];
			else
				triangle[i][j] = 0;
		}
	}

	// Collapsing triangle from bottom
	for (int i = rows-1; i >= 0; i--){
		for (int j = 0; j < i; j++){
			if (triangle[i][j] > triangle[i][j+1])
				triangle[i-1][j] += triangle[i][j];
			else 
				triangle[i-1][j] += triangle[i][j+1];
		}
	}

	// Final number of top is maximum total from top to bottom
	cout << triangle[0][0] << endl;

	printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}