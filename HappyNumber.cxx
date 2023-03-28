/*
Write an algorithm to determine if a number n  is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return TRUE if n is a happy number, and FALSE if not.
*/

#include<cmath>
#include<iostream>
using namespace std;

int SumDigits(int number)
{
    int totalSum = 0;
    while (number > 0)
    {
        int digit = number % 10;
        number = std::floor(number / 10);
        totalSum += digit * digit;
    }
    return totalSum;
}

bool IsHappyNumber(int n){
    int fast=n;
    int slow=n;
    do  {
        fast=SumDigits(SumDigits(fast));
        slow=SumDigits(slow);
    }while( (fast!=slow) && (fast!=1));
    return fast==1;
}

int main(){
    cout << IsHappyNumber(2147483646) << endl;
    cout << IsHappyNumber(1) << endl;
    cout << IsHappyNumber(19) << endl;
    cout << IsHappyNumber(9) << endl;
    return 0;
}