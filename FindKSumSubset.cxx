/*
Given a set of n positive integers, find all the possible subsets of integers that sum up to a number k.
 1<=n<=10
 1<=x<=100, where x is any number of input set
 1<=k<=10^3

*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

void GetKSumSubset(vector<int>&v, vector<int>temp,int index,int targetSum,vector<vector<int>>& r) {

    if (index==v.size()) {
        int sum=0;
        sum=accumulate(temp.begin(),temp.end(),sum);
        if(sum==targetSum) 
          r.push_back(temp);
          return ;
    }

    // two possiblities
    // add the current index number
    temp.push_back(v[index]);
    GetKSumSubset(v,temp,index+1,targetSum,r);
    temp.pop_back();
    GetKSumSubset(v,temp,index+1,targetSum,r);
}

vector<vector<int>> GetKSumSubsets(vector<int> v, int targetSum)
{
        vector<vector<int>> r;
        vector<int>temp;
        GetKSumSubset(v,temp,0,targetSum,r);
        return r;
}

int main(){
    vector<vector<int>> r;
    r = GetKSumSubsets({8,13,4,9},17);
    for(auto x:r) {
        cout << "[";
        for(auto y: x) {
            cout << y <<",";
        }
        cout << "],";
    }
    cout<< endl;
    return 0;
}