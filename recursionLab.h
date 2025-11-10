#include <iostream>
#include <string>
#include <cstdlib> // for abs

using namespace std;

// Write a function lineOfStars() that prints a line of n stars.
// Example: lineOfStars(3) returns "***"
//          lineOfStars(0) returns ""
// You may not use a loop.
string lineOfStars(int n) {
    if (n <= 0) return "";
    return "*" + lineOfStars(n - 1);
}

// Write a function power() that will
//    compute the x to the power of n recursively
// if the power is invalid, return 0
float power(float x, int n) {
    if (n < 0) return 0;       // invalid exponent
    if (n == 0) return 1;      // base case
    return x * power(x, n - 1);
}

/*
Write a function stars(int n) that prints the shape below.
You may call lineOfStars as a subroutine.
You may not use a loop.  
stars(4);

should display:

****
***
**
*
**
***
****

*/
void stars(int n) {
    if (n <= 0) return;

    // print top descending part
    cout << lineOfStars(n) << endl;

    stars(n - 1);  // recursive middle

    // print bottom ascending part
    if (n > 1)     // ensure middle star printed once only
        cout << lineOfStars(n) << endl;
}

// Write a *recursive* function that will check if
//    a string is a palindrome
bool isPalindromeR(string s)
{
    if (s.length() <= 1) return true;               // base case
    if (s.front() != s.back()) return false;        // check ends
    return isPalindromeR(s.substr(1, s.length() - 2)); // recurse inwards
}


// Write a function that will return the reverse of a string
// The function should be recursive
string reverse(string s)
{
    if (s.length() <= 1) return s;
    return s.back() + reverse(s.substr(1, s.length() - 2)) + s.front();
    // Alternate simpler approach:
    // return reverse(s.substr(1)) + s[0];
}

// Write a function that returns the sum of the decimal digits of n.
// Example: sumDigits(12345) returns 15
//          sumDigits(-4096) returns 19
// Treat n as its absolute value.
int sumDigits(int n) {
    n = abs(n);                          // ensure positive
    if (n < 10) return n;                // base case
    return (n % 10) + sumDigits(n / 10); // recurse
}

// Write a function that returns how many times x appears
// in the first n elements of the array arr.
int countOccurrences(const int* arr, int n, int x) {
    if (n == 0) return 0; // base case
    return (arr[0] == x ? 1 : 0) + countOccurrences(arr + 1, n - 1, x);
}
