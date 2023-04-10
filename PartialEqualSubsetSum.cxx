/*
Given a non-empty array of positive integers,
determine if the array can be divided into two subsets so that the sum of both the subsets is equal.

*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

bool CanPartitionArray(vector<int> arr)
{
    int sum=0;
    sum=accumulate(arr.begin(),arr.end(),0);
    if(sum%2) return false;
    sum/=2;
    // Can we find a subset with sum equal to sum;
   vector<bool>dp(sum+1,0);
    dp[0]=1;
    for(auto x: arr){
         // To change the values of all possible sum
        // values to 1
        for(int j = sum; j >= x; j--)
        {
            if (dp[j - x] == 1)
                dp[j] = 1;
        }
    }
    return dp[sum];
}

int main(int argc, char const *argv[])
{
    cout<< CanPartitionArray({3,1,1,2,2,1})<<endl;
    cout<< CanPartitionArray({1,3,7,3})<<endl;
    cout<< CanPartitionArray({1,2,3})<<endl;
    cout<< CanPartitionArray({1,3,4,8})<<endl;
    cout<< CanPartitionArray({1,2,5})<<endl;
    return 0;
}
