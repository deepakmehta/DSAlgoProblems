/*
Given an array of integers in which every element in the list appears twice except for one, find the element that occurs once.
Note: Solution must have linear runtime and constant memory complexity.

*/

#include <iostream>
#include<vector>
using namespace std;

int SingleNumber(vector<int> nums)
{
     int singleNum=0;
    for(auto x: nums){
      singleNum^=x;
    }
    return singleNum;
}

int main(int argc, char const *argv[])
{
    cout << SingleNumber({1,2,2,1,4}) << endl;
    return 0;
}
