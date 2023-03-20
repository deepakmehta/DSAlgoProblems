/*
Given an array, nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n/2⌋
 times. You may assume that the majority element always exists in the array.

Constraints:
  * n ==nums.length
  * 1<=n<=5*10^4
  * -10^9<<nums[i]<<10^9
*/
#include<vector>
#include<iostream>
using namespace std;

int FindMajorityElement(vector<int> nums)
{
    int majorityElem=-1;
    int freq=0;
    for(auto x: nums){
      if(freq==0) {
        majorityElem=x;
        freq++;
      } else {
        if( x==majorityElem) {
            freq++;
        } else {
            freq--;
        } 
      }
    }
    return majorityElem;
}

int main(int argc, char const *argv[])
{
    cout << FindMajorityElement({1, 2, 1, 1, 1}) << endl;
    cout << FindMajorityElement({7, 7, 5, 5, 7, 5, 7, 5, 7, 5, 7, 5, 7, 7, 5, 5, 7, 5, 5}) << endl;
    cout << FindMajorityElement({2, 2, 1, 1, 1, 2, 2}) << endl;
    cout << FindMajorityElement({3, 2, 3}) << endl;
    cout << FindMajorityElement({1, 1, 1, 1, 1, 1, 4, 4, 3, 1, 1}) << endl;
    cout << FindMajorityElement({2, 2, 1, 1, 1, 2, 2}) << endl;
    cout << FindMajorityElement({3, 2, 3}) << endl;
    cout << FindMajorityElement({1, 1, 1, 1, 1, 1, 4, 4, 3, 1, 1}) << endl;
    return 0;
}
