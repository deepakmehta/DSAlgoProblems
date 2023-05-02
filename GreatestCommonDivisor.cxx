/*
Given 2 non-negative integers A and B, find gcd(A, B).
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both A and B fit in a 32-bit signed integer.
Note: DO NOT USE LIBRARY FUNCTIONS

*/

/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */

#include<iostream>
using namespace std;

int gcd(int A, int B) {
     int minimum = min(A,B);
     int maximum=max(A,B);
    //int gcd=1;
     for(int i= (int)(minimum/2); i>0;--i){
        if(!(maximum%i)) return i;
     }
     return 1;
}

int main(int argc, char const *argv[])
{
    cout << gcd(6,9) << endl;
    return 0;
}
