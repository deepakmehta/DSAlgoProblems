/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s)
{
    vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));

    for(int i=0;i<s.size();++i){
        dp[i][i]=1;
        
    }

for(int i=0;i<s.size()-1;++i){
        if(s[i]==s[i+1]) dp[i][i+1]=2;
        else dp[i][i+1]=1;
}

for(int width=2; width<s.size();++width) {
    for(int i=0;i<s.size()-width;++i){
        if(s[i]==s[i+width]) {
             dp[i][i+width]=dp[i+1][i+width-1]+2;
        }else {
            
            dp[i][i+width]=max(dp[i+1][i+width],dp[i][i+width-1]);
            
        }
    }
    
}
    return dp[0][s.size()-1];

}

int main(int argc, char const *argv[])
{
    cout << longestPalindromeSubseq("bbbab") << endl;
    cout << longestPalindromeSubseq("cbbd") << endl;
    return 0;
}
