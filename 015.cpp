// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
// there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?

#include <iostream>
// Note: using the InfInt header file to deal with big numbers
#include "InfInt.h" //https://sercantutar.github.io/infint/
using namespace std;

InfInt factorial(int n);

int main(){
    // For the 2x2 grid example:
    // If we consider the route as a sequence of letters, R and D
    // the number of routes is simply the combinations of R and D
    // where there are 2 Rs and 2 Ds, since to reach the bottom right,
    // you must move across the width and down the height.
    // This is equivalent to 4C2 or 4! / 2!2!
    // or: (w+h)!  / w!h! ; where w is width and h is height

    cout << factorial(40) / (factorial(20) * factorial(20)) << endl; 
    return 0;
}

InfInt factorial(int n){
    InfInt factorial = 1;
    for (int i = 2; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}