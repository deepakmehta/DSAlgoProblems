#include <vector>
#include <iostream>
using namespace std;

int RobHouses(vector<int> nums)
{
    if (nums.empty()) return 0;
    vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
   
    dp[0][0]=0;
    dp[0][1]=nums[0];

    for ( int i = 1; i < nums.size();++i) {
        dp[i][0]= max(dp[i-1][1],dp[i-1][0]);
        dp[i][1] = dp[i-1][0]+nums[i];
    }
    return max( dp[nums.size()-1][0],
                dp[nums.size()-1][1]);
}

int main() {
    vector<int> abc{300,600,100,200,400};
    cout << RobHouses(abc) << endl;
    return 0;

}