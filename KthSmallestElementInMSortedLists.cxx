/*
Given m number of sorted lists in ascending order and an integer k, find the kth smallest number among all the given lists.
Constraints:
* If k is greater than the total number of elements in the input lists, return the greatest element from all the lists.
* If there are no elements in the input lists, return 0.

*/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int KSmallestNumber(std::vector<std::vector<int>> list, int k){
   // want to have a min heap
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minheap;
   for(int i=0; i<list.size();++i){
    vector<int> x = list[i];
    if (!x.empty()) {
        minheap.push(pair<int,pair<int,int>>(x[0],pair<int,int>(0,i)));
    }
   }
   // all lists are empty
   if(minheap.empty()) return 0;
   int ksmallest=-1;
   while(k-->0) {
       if(minheap.empty()) break;
       pair<int,pair<int,int>> smallest=minheap.top();
       minheap.pop();
       ksmallest=smallest.first;
       if( list[smallest.second.second].size() >(smallest.second.first)+1) {
         minheap.push(pair<int,pair<int,int>>(list[smallest.second.second][smallest.second.first+1],
                               pair<int,int>(smallest.second.first+1,smallest.second.second)));
       }
   }
  return ksmallest;
}

int main() {
    cout << KSmallestNumber({{2,6,8},{3,7,10},{5,8,11}},5)<<endl;
    cout << KSmallestNumber({{1,2,3},{4,5},{6,7,8,15},{10,11,12,13},{5,10}},50)<<endl;
    cout << KSmallestNumber({{1,1,1},{1,1,1}},4)<<endl;
    cout << KSmallestNumber({{4,6},{2,3},{8,9}},10)<<endl;
    cout << KSmallestNumber({{5,8,9,17},{1,6,6,6},{8,17,23,24}},6)<<endl;
}
