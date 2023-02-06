#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and 0 < x <= d.
i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

 
*/



class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        
        vector<vector<int>> dp(arr.size(),vector<int>(2,0));
        
        for ( int i = 0 ; i < arr.size() ; ++i) {
            
            for ( int j = i-1; ((j >=0)&& (j >=i-d));--j) {
                if (arr[j] > arr[i]) break;
                dp[i][0] = max ( dp[i][0],1+dp[j][0]);
            }    
        }
        
        
        for ( int i = arr.size() ; i >= 0 ; --i) {
            
            for ( int j = i+1; ((j <arr.size())&& (j <=i+d));++j) {
                if (arr[j] > arr[i]) break;
                dp[i][1] = max ( dp[i][1],1+dp[j][1]);
            }
        }
       
        
        int maxV=0;
        vector<int> finaldp(arr.size(),0);
        for ( int i = 0 ; i < arr.size() ; ++i) {
            for ( int j = i-1; ((j >=0)&& (j >=i-d));--j) {
                if (arr[j] > arr[i]) break;
                finaldp[i]=max(finaldp[i],1+max(dp[j][0],dp[j][1]));
            }
            
            for ( int j = i+1; ((j <arr.size())&& (j <=i+d));++j) {
                if (arr[j] > arr[i]) break;
                finaldp[i]=max(finaldp[i],1+max(dp[j][0],dp[j][1]));

            }
                               
            maxV = max(maxV, finaldp[i]);
        }
        
        return maxV+1;
    }
};

int main( ){
    Solution  s;
    vector<int> inp{6,4,14,6,8,13,9,7,10,6,12};
    cout << s.maxJumps(inp,2) << endl;;
    return 0;
}