/*
Given a string palString, return the longest palindromic substring in palString.
Constraints:
1<=palstring.length<=1000
palstring consists of digits and english letters
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

string longestPalindromeSubString(string s)
{
    if(s.empty())return "";
    int startIndex=0;
    vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
    int maxlen=0;
    for(int i=0;i<s.size();++i){
        dp[i][i]=1;
        startIndex=i;
        maxlen=1;
        
    }

for(int i=0;i<s.size()-1;++i){
        if(s[i]==s[i+1]) {
         maxlen=2;
         startIndex=i;
         dp[i][i+1]=true;
        }
        else dp[i][i+1]=false;
}

for(int width=2; width<s.size();++width) {
    for(int i=0;i<s.size()-width;++i){
        if(s[i]==s[i+width]) {
             dp[i][i+width]=dp[i+1][i+width-1]?true:false;
           //  maxlen=max(maxlen,width);
           if(dp[i][i+width] && (width>(maxlen-1))) {
            maxlen=width+1;
            startIndex=i;
           }
        }else {
            
            dp[i][i+width]=false;
            
        }
    }
    
}
    return s.substr(startIndex,maxlen);

}

int main(int argc, char const *argv[])
{
    cout << longestPalindromeSubString("bbbab") << endl;
    cout << longestPalindromeSubString("cbbd") << endl;
    return 0;
}
