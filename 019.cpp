// You are given the following information,
// but you may prefer to do some research for yourself.

// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, 
// but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century 
// (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>

using namespace std;

int main(){
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sundayCount = 0;
    int day = 1; // 1 Jan 1900 was Monday 

    for (int year = 1900; year < 2000; year++){

        if (year % 4 == 0 && year % 400){
            daysInMonth[1] = 29;        
        } else {
            daysInMonth[1] = 28;
        }

        for (int month = 0; month < 12; month++){
            day = (day + daysInMonth[month]) % 7;

            if (day == 0){
                sundayCount++;
            }
        }
    }
    cout << sundayCount << endl;
}