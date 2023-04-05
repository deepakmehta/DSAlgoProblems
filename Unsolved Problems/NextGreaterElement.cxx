/*
Let's first define the "next greater element" of some element x in an array of integers as the first element
we encounter to the right of x (that is, whose index is greater than the index of x) whose value is also greater than x.
In mathematical terms, y is the next greater element of x, if and only if:

* y > x
* Index of y > Index of x
* the first two conditions don't hold true for any other element z, where index of z < index of y
You are given two distinct integer arrays, nums1 and nums2, where nums1 is subset of nums2
For each index i, find the index j such that nums1[i]==nums2[j] and determine the next greater element of nums2[j] in nums[2].
If there is no greater element, the answer to this query is -1.

*/

#include <iostream>
#include <vector>
#include<map>
#include<set>
using namespace std;

struct cmp {
bool operator()(const pair<int,int>& first, const pair<int,int>& second) const{
    cout << "Comparing: " << first.first << " : " << first.second << " with: " 
         << second.first << "  : "  << second.second << endl;
    if (second.first>first.first) {
        if (second.second>first.second){
            cout << "true" << endl;
            return true;
        } else {
            return false;
        }
    } else {

        if (first.second<second.second){
            cout << "true" << endl;
            return true;
        }

    }

    cout << "false" << endl;
    return false;
}
};
vector<int> NextGreaterElement(vector<int> nums1, vector<int> nums2)
{
    set< pair<int,int>, cmp> m;  
    map<int,int> numToIndexmap;
    for(int i=0; i<nums2.size();++i){
        cout << "inserting: " << i << ", " << nums2[i] << endl;
        numToIndexmap.insert(pair<int,int>(nums2[i],i));
       pair<set<pair<int,int>,cmp>::iterator,bool> abc= m.insert(pair<int,int>(nums2[i],i));
       cout << " i: " << (*(abc.first)).first << (*(abc.first)).second << " val: " << abc.second << endl;
    }
    
    for(auto x: m) {
        cout << x.first << " , " << x.second << endl;
    }

    vector<int> r;
    for(auto x: nums1){
        pair<int,int>xyz(x,numToIndexmap[x]);
      set<pair<int,int>, cmp>::const_iterator i =m.find(xyz);
      if(i==m.end()){
        r.push_back(-1);
      } else {
        if (++i != m.end()){
            r.push_back((*(i)).first);
        } else {
            r.push_back(-1);
        }
      }
    }
    return r;
}

 int main(int argc, char const *argv[])
 {
    vector<int> r;
    // r= NextGreaterElement({2,4},{1,2,3,4});
    // for( auto y: r) {
    //     cout << y << ",";
    // }
    // cout << endl;
    // r= NextGreaterElement({1,3},{1,2,3,4});
    // for( auto y: r) {
    //     cout << y << ",";
    // }
    // cout << endl;
    // r= NextGreaterElement({1,10},{1,3,5,10});
    // for( auto y: r) {
    //     cout << y << ",";
    // }
    // cout << endl;
    // r= NextGreaterElement({15,13},{10,12,13,15,9});
    // for( auto y: r) {
    //     cout << y << ",";
    // }
    // cout << endl;
       r= NextGreaterElement({4,1,2},{1,3,4,2});
    for( auto y: r) {
        cout << y << ",";
    }
    cout << endl;
    return 0;
 }
 