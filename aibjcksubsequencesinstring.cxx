/* Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
*/



#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        if (s.empty()) return 0;
        
        vector<vector<int>> dp(s.size()+1,vector<int>(3,0));
        dp[0][0]=0;
        dp[0][1]=0;
        dp[0][2]=0;
        for ( int i = 1; i < s.size()+1;++i) {
            if (s[i-1] == 'a') {
                dp[i][0] = dp[i-1][0] *2 +1;

                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
            } else if ( s[i-1]=='b') {
                
                dp[i][1] = dp[i-1][0];
                if ( dp[i-1][1] >0) {
                   dp[i][1] +=dp[i-1][1]*2;
                }

                dp[i][0] = dp[i-1][0];
                dp[i][2] = dp[i-1][2];
            } else if ( s[i-1] == 'c') {
                dp[i][2] = dp[i-1][1];
                if ( dp[i-1][2] >0) {
                   dp[i][2] +=dp[i-1][2]*2;
                }
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
            }
        }
        
      return dp[s.size()][2];
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
 //   cin>>t;
 //   while(t--) {
 //       string s;
 //       cin>>s;
        Solution obj;
        string s("abcabc");
      cout<<obj.fun(s)<<endl;
   // }
	return 0;
 }

