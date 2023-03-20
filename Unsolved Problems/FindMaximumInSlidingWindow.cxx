/*
Given an integer array nums and a window of size w,
find the current maximum value in the window as it slides through the entire array.

Note: 
If the window size is greater than the array size, we consider the entire array as a single window.

Constraints:
1<=nums.length<=10^3
-10^4 <=nums[i] <=10^4
1<=w
*/
#include<vector>
#include<iostream>
using namespace std;

vector<int> FindMaxSlidingWindow(vector<int> nums, int windowSize)
{
    vector<int> r;
    if(nums.empty()) return r;
    int sw=0;
    int ew=0;
    int wm=nums[0];
    while(ew<nums.size()){
      if(ew-sw+1<windowSize) {
         wm=max(wm,nums[ew++]);
      } else if(ew-sw+1==windowSize) {
        wm=max(wm,nums[ew++]);
        r.push_back(wm);
        // lets try to contract the window by 1
        if(wm!=nums[sw++]) {
        } else {
            // we need to iterate and find the maximum
            int localmax=nums[sw];
            for(auto x=sw+1;x<=ew;x++) {
                localmax=max(localmax,nums[x]);
            }
            wm=localmax;
        } 
      }
    }
    if(r.empty()) r.push_back(wm);
    return r;
}

int main(int argc, char const *argv[])
{
    vector<int> result;
    result=FindMaxSlidingWindow({1,2,3,4,5,6,7,8,9,10},3);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    result=FindMaxSlidingWindow({3,3,3,3,3,3,3,3,3,3},4);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    result=FindMaxSlidingWindow({10,6,9,-3,23,-1,34,56,67,-1,-4,-8,-2,9,10,34,67},2);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    result=FindMaxSlidingWindow({4,5,6,1,2,3},1);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    result=FindMaxSlidingWindow({9,5,3,1,6,3},2);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    result=FindMaxSlidingWindow({1,2},2);
    for(auto x: result) {
        cout<< x << "," ;
    }
    cout<<endl;
    return 0;
}
