/*
You’re given an integer array, nums.
If any value inside the array appears at least twice, return TRUE. Otherwise, return FALSE.

Constraints:
1<=nums.length <=10^5
-10^9 <=nums[i]<=10^9

*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool ContainsDuplicate(vector<int> nums)
{
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();++i){
        if(nums[i]==nums[i-1])return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << ContainsDuplicate({1,3,6,2,3,5,4,8,7,6,2,3,5,2,9,4,3}) << endl;
    cout << ContainsDuplicate({1,2,3,4,5,6,7,8,9,0}) << endl;
    cout << ContainsDuplicate({0,9,8,7,6,5,5,4,4,3,2,1}) << endl;
    return 0;
}
