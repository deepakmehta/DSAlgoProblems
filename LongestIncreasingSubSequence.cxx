/*
    Given an integer array, nums, return the length of the longest strictly increasing subsequence.
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int LongestSubsequence(vector<int> nums)
{
    if(nums.empty()) return -1;
    vector<int>dp(nums.size(),1);
    dp[0]=1;
    for(int i=1;i<nums.size();++i) {
        for(int j=0; j<i;++j) {
            dp[i]=max(dp[i],nums[i]>nums[j]?dp[j]+1:0);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[])
{
    cout << LongestSubsequence({10,9,2,5,3,7,101,18}) << endl;
    cout << LongestSubsequence({7,7,7,7,7,7,7}) << endl;
    cout << LongestSubsequence({0,1,0,3,2,3}) << endl;

    return 0;
}
