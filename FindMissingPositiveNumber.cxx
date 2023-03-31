/*
Given an unsorted integer array, nums, return the smallest missing positive integer. Create an algorithm that runs with an O(n)
 time complexity and utilizes a constant amount of space.

*/

#include <iostream>
#include <vector>
using namespace std;

int SmallestMissingPositiveInteger(vector<int> nums)
{
    int size=nums.size();
    for(int i=0; i<nums.size();++i){
        if(nums[i]!=i+1){
            if((nums[i]>0) && (nums[i]<size)) {
                int temp =nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
                i--;
            }
        }
    }
    for(int i=0; i<nums.size();++i){
        if(nums[i]!=i+1) return (i+1);
    }
    return size+1;
}

int main(int argc, char const *argv[])
{
    cout <<SmallestMissingPositiveInteger({55,22,52,100,1,3,-5})<<endl;
    cout <<SmallestMissingPositiveInteger({1,2,3,5})<<endl;
    cout <<SmallestMissingPositiveInteger({2,3,4,5,6})<<endl;
    cout <<SmallestMissingPositiveInteger({-1,-2,-3,-4})<<endl;
    return 0;
}
