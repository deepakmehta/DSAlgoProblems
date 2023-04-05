/*
Given an integer n, we need to calculate the integer it would be if we reversed its bits. When we say “reverse” we don’t mean flipping the 
0s to 1s and vice versa, but simply reversing the order in which they appear–from left-to-right to right-to-left. We need to return the integer the reversed bits result in.
*/
#include<iostream>
using namespace std;

int ReverseBits(int n)
{
    int returnVal=0;
    for(int i=0; i<sizeof(int)*8;++i){
        cout << "i:" << i << endl;
        if(n&(1<<i)) {
            cout << "bit found" << endl;
            returnVal|=(1<<((sizeof(int)*8)-i-1));
        }
    }
    return returnVal;
    
}

// function to reverse bits of a number
unsigned int reverseBits2(unsigned int n)
{
    unsigned int rev = 0;
 
    // traversing bits of 'n' from the right
    while (n > 0) {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;
 
        // if current bit is '1'
        if (n & 1 == 1)
            rev ^= 1;
 
        // bitwise right shift
        // 'n' by 1
        n >>= 1;
    }
 
    // required number
    return rev;
}
int main(int argc, char const *argv[])
{
    cout << ReverseBits(2) << endl;
    //cout << ReverseBits(0)<< endl;
    return 0;
}
