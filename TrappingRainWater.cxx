/*
Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Input: arr[] = {2, 0, 2}
Output: 2
Explanation: The structure is like below.
We can trap 2 units of water in the middle gap.



Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
Explanation: Structure is like below.
We can trap “3 units” of water between 3 and 2,
“1 unit” on top of bar 2 and “3 units” between 2 and 4.



Input: arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
Output: 6
Explanation: The structure is like below.
Trap “1 unit” between first 1 and 2, “4 units” between
first 2 and 3 and “1 unit” between second last 1 and last 2

*/

#include<vector>
#include<iostream>
using namespace std;

class TrappingRainWater {

public:
  int Solve(vector<int>& arr) {
    vector<int> prefixHeight(arr.size(),0);
    vector<int> suffixHeight(arr.size(),0);
    
    int lheight=0;
    int rh =0;
    for( int i = 0; i < arr.size();++i) {
        prefixHeight[i] = lheight;
        lheight = max(lheight, arr[i]);
        suffixHeight[arr.size()-i-1] = rh;
        rh = max(rh, arr[arr.size()-i-1]);
    }

   int trappedWater=0;
   for ( int  i = 0 ; i < arr.size(); ++i) {
      int minh = min(prefixHeight[i],suffixHeight[i]);
      trappedWater += (minh>=arr[i]) ? (minh-arr[i]):0;
   }

    return trappedWater;
  }
};

int main() {
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    TrappingRainWater Solver;
    cout << " Rainwater Trapped: " <<  Solver.Solve(arr) << endl;
    return 0;
}