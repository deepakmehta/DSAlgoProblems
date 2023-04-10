/*
You are climbing a staircase. It takes n steps to reach the top. Each time, you can either climb 1 or  2 steps.
In how many distinct ways can you climb to the top?

*/

#include<iostream>
#include<vector>
using namespace std;

int ClimbStairs(int n)
{   
    vector<int>dp(n,0);
    dp[0]=1;
    dp[1]=2;
    if(n==0) return 1;
    if(n==1) return 2;
    for(int x=2; x <n;++x){
        dp[x]=dp[x-1]+dp[x-2];
    }
    return dp[n-1];
}


int main(int argc, char const *argv[])
{
    cout << ClimbStairs(5) << endl;
    cout << ClimbStairs(10) << endl;

    return 0;
}

