/*
An input array, nums containing non-zero integers, is given, where the value at each index represents the number of places to skip forward (if the value is positive) or backward (if the value is negative).
When skipping forward or backward, wrap around if you reach either end of the array.
For this reason, we are calling it a circular array.
Determine if this circular array has a cycle.
A cycle is a sequence of indices in the circular array characterized by the following:

Note: 
* The same set of indices is repeated when the sequence is traversed in accordance with the aforementioned rules.
* The length of the sequence is at least two.
* The loop must be in a single direction, forward or backward.
nums[i] !=0
*/

#include <iostream>
#include <vector>
using namespace std;

int nextPosition(vector<int> &nums, int idx, bool &isForward) {
        
        int n=nums.size();
        bool direction= (nums[idx]>=0) ? true : false;

        if(direction != isForward)
            return -1;

        int nextIndex= ((idx+nums[idx])%n+n)%n;

        if(nextIndex==idx)
            return -1;
        
        return nextIndex;

    }

bool CircularArrayLoop(vector<int> nums){

  for( int indexStart=0; indexStart<nums.size();++indexStart){
    int fast=indexStart;
    int slow=indexStart;
    bool isForward = nums[indexStart]>0? true: false;
    while(true) {
         slow= nextPosition(nums, slow, isForward);
                if(slow==-1)
                    break;
                
                fast= nextPosition(nums, fast, isForward);
                if(fast==-1)
                    break;

                fast= nextPosition(nums, fast, isForward);
                if(fast==-1)
                    break;
                
                if(slow==fast)
                    return true;
        
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
       

    return 0;
}
