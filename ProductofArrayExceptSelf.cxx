/*
You’re given an integer array, arr. Return a resultant array so that res[i] is equal to the product of all the elements of arr except arr[i].

Write an algorithm that runs in O(n) time without using the division operation.
*/
#include<vector>
#include<iostream>
using namespace std;

vector<int> ProductOfSelf(vector<int> arr)
{
    if(arr.empty())return {};
    vector<int> prefixMul(arr.size(),1);
    vector<int> suffixMul(arr.size(),1);
    for(int i=1; i<arr.size();++i){
        prefixMul[i]=prefixMul[i-1]*arr[i-1];
    }
    for(int i=arr.size()-2; i>=0;--i){
        suffixMul[i]=suffixMul[i+1]*arr[i+1];
    }
   
   vector<int>r;
   for(int i=0; i<arr.size();++i){
    r.push_back(prefixMul[i]*suffixMul[i]);
   }

    return r;
}

int main(int argc, char const *argv[])
{
    vector<int>r;
    r=ProductOfSelf({0,-1,2,-3,4,-2});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}


