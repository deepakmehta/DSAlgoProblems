/*
Given an array of positive integers nums and a positive integer target,
find the window size of the shortest contiguous subarray whose sum is greater than or equal to the target value.
If no subarray is found, 0 is returned.

Constraints:
*  1<=targets<=10^9
* 1<=nums.length<=10^5
* 1<=nums[i]<=10^4
*/

#include <climits>
#include <vector>
#include<iostream>
using namespace std;

int MinSubArrayLen(int target, vector<int> nums)
{
    int s = 0, e = 0;
    int currentSum = 0;
    int minlength = INT_MAX;
    while (e < nums.size())
    {
        currentSum += nums[e];
        if (currentSum >= target)
        {
            // lets move the s till the sum is greater than target
            while ((currentSum >= target))
            {
                currentSum -= nums[s++];
            }
            minlength = min(minlength, e - s + 2);
        }
        e++;
    }
    return minlength==INT_MAX?0:minlength;
}

int main(int argc, char const *argv[])
{
    cout << MinSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << endl;
    cout << MinSubArrayLen(4, {1, 4, 4}) << endl;
    cout << MinSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}) << endl;
    cout << MinSubArrayLen(10, {1, 2, 3, 4}) << endl;
    cout << MinSubArrayLen(5, {1, 2, 1, 3}) << endl;
    return 0;
}
