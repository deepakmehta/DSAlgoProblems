/*
You're given an integer total and a array of integers called coins.
The variable coins hold a array of coin denominations, and total is the total amount of money.

You have to find the minimum number of coins that can make up the total amount by using any combination of the coins.
If the amount can't be made up, return -1. If the total amount is 0, return 0.

Note: you may assume we have infintie amount of supply for each coin.

*/

#include <iostream>
#include <vector>
using namespace std;

int FindCoinChange(vector<int> coins, int total)
{
    vector<vector<int>> dp(coins.size(), vector<int>(total + 1, -1));
    for (int i = 0; i < coins.size(); ++i)
    {
        dp[i][0] = 0;
    }

    if (total > coins[0])
    {
        for (int i = 0; i < total + 1; ++i)
        {
            if (!(i < coins[0]) && !(i % coins[0]))
                dp[0][i] = i / coins[0];
        }
    }

    for (int i = 1; i < coins.size(); ++i)
    {
        for (int j = 1; j < total + 1; ++j)
        {
            if ((j < coins[i]))
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                int c = dp[i][j - coins[i]];
                if (c != -1)
                {
                    if (dp[i][j] == -1)
                    {
                        dp[i][j] = c + 1;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j], c + 1);
                    }
                }
            }
        }
    }

    return dp[coins.size() - 1][total];
}

int main(int argc, char const *argv[])
{
    cout << FindCoinChange({1,2,5},11) << endl;
    cout << FindCoinChange({2},4) << endl;
    cout << FindCoinChange({5},3) << endl;
    cout << FindCoinChange({1,2,5},0) << endl;
    cout << FindCoinChange({2, 3, 4, 6, 8}, 23) << endl;
    return 0;
}
