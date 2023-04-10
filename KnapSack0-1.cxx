/*
Suppose you have the array of weights and corresponding values for n  items.
You have a knapsack that can carry a specific amount of weight at a time called capacity.

You need to find the maximum profit of items using the sum of values of the items you can carry in a knapsack.
The sum of the weights of the items should be less than or equal to the knapsack’s capacity.

If any combination can’t make the given knapsack capacity of weights, then return 0.
*/

#include<vector>
#include<iostream>
using namespace std;

int FindMaxKnapsackProfit(int capacity, vector<int> weights, vector<int> values)
{
    vector<vector<int>>dp(values.size(),vector<int>(capacity+1,0));
    //initial first element
    for(int i=0; i<capacity+1;++i){
        if(weights[0]>i){
            dp[0][i]=0;
        } else {
            dp[0][i]=values[0];
        }
    }

    for(int i=1; i<weights.size();++i){
        for(int j=0; j<capacity+1;++j){
        if(j<weights[i]){
            dp[i][j]=dp[i-1][j];
        } else {
            dp[i][j]=max(dp[i-1][j],(values[i]+dp[i-1][j-weights[i]]));
        }
    }
    }

    return dp[weights.size()-1][capacity];
}

int main(int argc, char const *argv[])
{
    cout << FindMaxKnapsackProfit(6,{1,2,3,5},{1,5,4,8}) << endl;
    cout << FindMaxKnapsackProfit(3,{4},{2}) << endl;
    cout << FindMaxKnapsackProfit(3,{2},{3}) << endl;
    cout << FindMaxKnapsackProfit(10,{3,6,10,7,2},{12,10,15,17,13}) << endl;
    cout << FindMaxKnapsackProfit(30,{10,20,30},{22,33,44}) << endl;
    return 0;
}
