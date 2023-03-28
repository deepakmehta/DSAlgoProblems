/*
Given an array where the element at the index i represents the price of a stock on day i,
find the maximum profit that you can gain by buying the stock once and then selling it.
Note: Stock can only be purchased on a single day and sold on a different day.
      If no profit can be achieved, we return zero.

Constraints:
* We can’t sell before buying a stock, that is,
  the array index at which stock is bought will always be less than the index at which the stock is sold.
* 1<prices.length<10^5
* 0<=prices[i] <=10^5
*/
#include<vector>
#include<iostream>
using namespace std;

int MaxProfit(vector<int> stockPrices)
{
    int mp=0;
    int ws=0;
    int we=1;
    if(stockPrices.empty()) return 0;
    int min=stockPrices[ws];
    for(;we<stockPrices.size();++we) {
       if(stockPrices[we]<min) {
           // opportunity to buy at even lower
           // lets move the window
           int m=0;
           while(ws!=we){
             m=max(m,stockPrices[ws++]);
           }
          mp=max(mp,m-min);
          min=stockPrices[we];
          ws=we;
       }   
    }
           int m=0;
           while(ws<stockPrices.size()){
             m=max(m,stockPrices[ws++]);
           }
          mp=max(mp,m-min);
    
    return mp;
}

int main(int argc, char const *argv[])
{
    cout << MaxProfit({1,2,4,2,5,7,2,4,9,0,9}) << endl;
    cout << MaxProfit({7,1,5,3,6,4}) << endl;
    cout << MaxProfit({7,6,4,3,1}) << endl;
    cout << MaxProfit({2,6,8,7,8,7,9,4,1,2,4,5,8}) << endl;
    cout << MaxProfit({1,2}) << endl;
    return 0;
}
