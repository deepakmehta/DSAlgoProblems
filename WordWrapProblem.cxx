/*
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width).
Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width.
The word processors like MS Word do task of placing line breaks.
The idea is to have balanced lines.
In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces.

The extra spaces includes spaces put at the end of every line except the last one.
The problem is to minimize the following total cost.
 Cost of a line = (Number of extra spaces in the line)^3
 Total Cost = Sum of costs for all lines

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        vector<double> cost(nums.size()+1,INT_MAX);
        cost[nums.size()]=0;
        for(int i=nums.size()-1;i>=0;--i){
            int j=i;
            int curr_len=0;
            while(j<nums.size()){
                curr_len+=nums[j];
                if(curr_len<k){
                    cost[i]=min(cost[i],(cost[j+1]+pow(k-curr_len,3)));
                } else {
                    break;
                }
                j++;
            }
        }
        return cost[0];
    }
};

//{ Driver Code Starts.
int main()
{
    Solution obj;
    cout << obj.solveWordWrap({3,2,2,5}, 6) << endl;
    return 0;
}
