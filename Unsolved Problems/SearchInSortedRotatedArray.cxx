/*
Given a sorted integer array, nums, and an integer value, target, the array is rotated by some arbitrary number.
Search and return the index of target in this array.
If the target does not exist, return -1.

Note: 
All values in nums are unique.
The values in nums are in sorted in ascending order. The array may have been rotated by some arbitrary number.
*/

#include<vector>
#include<iostream>
using namespace std;

int BinarySearchRotated(vector<int>& nums, int low, int high, int target){
    if (high<low) return -1;
    if(high==low){
        if(nums[high]!=target)return -1;
        return high;
    }

    if(nums[low]<nums[high]){
        int pivot = (low+high)/2;
        if(target==nums[pivot])return pivot;
        if(target<nums[pivot]) {
            return BinarySearchRotated(nums,low,pivot,target);
        } else {
return BinarySearchRotated(nums,pivot,high,target);
        }
    } else {
        // there is an inflexion point in between
        int pivot = (low+high)/2;
        if(target==nums[pivot])return pivot;
        if(nums[low]<=nums[pivot]){
        if(target<nums[pivot]) {
             return BinarySearchRotated(nums,low,pivot-1,target);
        } else {
            return BinarySearchRotated(nums,pivot+1,high,target);
        }
        } else {
         if( (target<nums[pivot]) || target>nums[low]) {
             return BinarySearchRotated(nums,low,pivot-1,target);
        } else {
            return BinarySearchRotated(nums,pivot+1,high,target);
        }   
        
        }
    }
}
int BinarySearchRotated(vector<int> nums, int target)
{
	return BinarySearchRotated(nums,0,nums.size()-1,target);
    return -1;
}

int main(int argc, char const *argv[])
{
    cout<<BinarySearchRotated({6,7,1,2,3,4,5},3)<<endl;
    cout<<BinarySearchRotated({4,5,6,1,2,3},3)<<endl;
    cout<<BinarySearchRotated({4},1)<<endl;
    return 0;
}
