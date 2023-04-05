/*
For any n positive number in base 10, return the complement of its binary representation as an integer in base 10.
Constraints:
 0<=n<=10^9

*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int BitwiseComplement(int num){
    int temp=num;
    int mask=0;
    while(temp){
      mask<<=1;
      mask|=1;
      temp/=2;
    }
    return num^mask;
}
int BitwiseComplement2(int num){
  if (num == 0){ // if the value of num is 0, return 1
      return 1;
  }
  // converting the value into its binary representation and
  // counting the number of bits required by this number
  int bitCount = floor(log2(num)) + 1;
  // computing the all bits set of the number
  int allBitsSet = pow(2, bitCount) - 1;
  // flipping all bits of number by taking xor with all_bits_set
  return num ^ allBitsSet;
}

int main(int argc, char const *argv[])
{
    cout << BitwiseComplement2(42)<<endl;
    cout << BitwiseComplement2(8)<<endl;
    cout << BitwiseComplement2(233)<<endl;
    cout << BitwiseComplement2(100)<<endl;
    return 0;
}
