// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

// a2 + b2 = c2
// For example, 32 + 42 = 9 + 16 = 25 = 52.

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    for (int a = 1; a <= round((1000-3)/3); a++){
        for (int b = a + 1; b <= round((999-a)/2); b++){
            int c = 1000 - a - b;
            if (a*a + b*b == c*c){
                cout << a * b * c << endl;
                return 0;
            }
        }
    }
    return 0;
}