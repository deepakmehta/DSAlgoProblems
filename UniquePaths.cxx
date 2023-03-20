/*
An m∗n grid contains a robot.
Initially, the robot is located at the top-left corner of the grid at location grid[0][0].
The robot makes an attempt to move to the bottom-right corner of the grid at location grid[m - 1][n - 1].
At any one time, the robot can only move to the right or down.

Given the two integers, m and n,
return the total number of distinct paths that the robot can take to reach the bottom-right corner of the grid.

Constraints:
* 1<=m,n<=100

*/
                                
#include <iostream>
#include<vector>
using namespace std;

int UniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        dp[m - 1][i] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        dp[i][n - 1] = 1;
    }

    for (int i = m - 2; i >= 0; --i)
    {
        for (int j = n - 2; j >= 0; --j)
        {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0];
}


int main(int argc, char const *argv[])
{
    cout << UniquePaths(3, 7) << endl;
    cout << UniquePaths(3, 2) << endl;
    cout << UniquePaths(3, 3) << endl;
    cout << UniquePaths(7, 3) << endl;
    return 0;
}
