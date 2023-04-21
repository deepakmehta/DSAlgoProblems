/*
You’re given an array of positive integers, w, where w[i] describes the weight of the ith index.
You need to perform weighted random selection to return an index from the w array.
The larger the value of w[i], the heavier the weight is.
Hence, the higher the chances of its index being picked.
*/

#include<iostream>
#include<vector>
#include <map>
#include <iomanip>

using namespace std;

class RandomPickWithWeight
{
  // Constructor
     vector<int> cum_sum;
     int sum=0;
  public:
    RandomPickWithWeight(vector<int> w)
    { 
    
      for(auto x: w){
        sum+=x;
        cum_sum.push_back(sum);
      }
    }

    int pickindex()
    {
      int random = rand()%sum;
      // search for a number greater than equal to random
      int left=0;
      int right=cum_sum.size()-1;
      while(left<=right){
        int mid=(left+right)/2;
        if(random>cum_sum[mid]){
            right=mid-1;
        } else {
            left=mid+1;
        }
      }
      return right;
    }
};


int main()
{
  int counter = 900;
  vector<int> weights1 = {1, 2, 3, 4, 5};
  vector<int> weights2 = {1, 12, 23, 34, 45, 56, 67, 78, 89, 90};
  vector<int> weights3 = {10, 20, 30, 40, 50};
  vector<int> weights4 = {1, 10, 23, 32, 41, 56, 62, 75, 87, 90};
  vector<int> weights5 = {12, 20, 35, 42, 55};
  vector<int> weights6 = {10, 10, 10, 10, 10};
  vector<int> weights7 = {10, 10, 20, 20, 20, 30};
  vector<int> weights8 = {1, 2, 3};
  vector<int> weights9 = {10, 20, 30, 40};
  vector<int> weights10 = {5, 10, 15, 20, 25, 30};
  vector< vector<int>>weights = {weights1, weights2, weights3, weights4, weights5, weights6, weights7, weights8, weights9, weights10};
  map<int, int> dict;

  for(int i=0; i<weights.size(); i++)
  {
    cout << i + 1 << ".\tInput: " << PrintList(weights[i]) << ", pickindex() called " << counter << " times" << endl;
    RandomPickWithWeight obj(weights[i]);
    for(int j = 0; j < weights[i].size(); j++)
    {
      dict.insert({j, 0});
    }

    int result = 0;
    for(int k = 0; k < 1000; k++)
    {
      result = obj.pickindex();
      dict[result] += 1;
    }

    cout << string(100, '-') << endl;
    cout << "Indexes" << setw(4) << "|" << setw(10) 
         << " Weights" << setw(4) << "|" << setw(13)
         << "Occurences" << setw(4) << "|" << setw(12)
         << "Frequency" << setw(4) << "|" << setw(20)
         << "Expected Frequency" << endl;
    cout << string(100, '-') << endl;

    for (auto const& [key, val] : dict)
    {
      cout << left << setw(10) << key 
           << left << setw(4) << "|" << setw(10) << weights[i][key] 
           << left << setw(4) << "|" << setw(13) << val 
           << left << setw(4) << "|" << setw(12) << (float(float(val/float(1000))*float(100))) 
           << left << setw(4) << "|" << setw(12) << (float(float(weights[i][key])/(accumulate(weights[i].begin(), weights[i].end(), 0))*float(100))) << endl;      
    }
    cout << string(100, '-') << endl;
    dict.clear();
  }
}