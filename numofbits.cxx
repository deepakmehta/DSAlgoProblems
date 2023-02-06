#include<iostream>
using namespace std;


int NumberOf1Bits(uint32_t n)
{
    int num_bits=n%2;
    int k = 31;
    while( (k-->0)&&(n=n>>1)) {
        num_bits+=n%2;
    }
    return num_bits;
}

int main(){
    cout << NumberOf1Bits(0b11111111111111111111111111111111) << endl;
}


