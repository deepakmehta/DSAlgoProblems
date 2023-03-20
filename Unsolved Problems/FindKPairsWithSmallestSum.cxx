/*
Given two lists, and an integer k,
find k pairs of numbers with the smallest sum so that in each pair,
each list contributes one number to the pair.
Constraints:
* Input lists should be sorted in ascending order.
* If the value of k exceeds the total number of valid pairs that may be formed, return all the pairs
*/
#include <iostream>
#include <vector>
// #include<queue>
using namespace std;

// bool comp(vector<int> first,vector<int>second) {
//     return ((first[0]*first[1]) >(second[0]*second[1]));
// }

vector<vector<int>> KSmallestPairs(vector<int> list1, vector<int> list2, int k) {
    int pair1head=0, pair2end=0;
    int pair2head=0,pair1end=0;
    //priority_queue<vector<int>,vector<vector<int>>, comp>minheap;
    vector<vector<int>> r;
    while(k-->0){
        if( (pair1head==pair2end)&&(pair1end==pair2head)) {
            r.push_back(vector<int>{list1[pair2end++],list2[pair1end++]});
        } else {
            if(pair1end==list2.size()) {
                pair1end=0;
                pair1head++;
            }

            if(pair2end==list1.size()) {
                pair2end=0;
                pair2head++;
            }
            int first=INT_MAX;
            int second=INT_MAX;
            if(pair1head<list1.size()) {
                first=list1[pair1head]*list2[pair1end];
            }
            if(pair2head<list2.size()) {
                second=list2[pair2head]*list1[pair2end];
            }
            if (first<second) {
                r.push_back(vector<int>{list1[pair1head],list2[pair1end++]});
            } else if( second!=INT_MAX) {
                r.push_back(vector<int>{list1[pair2end++],list2[pair2head]});
            } else {
                break;
                // minheap.push(vector<int,int>(-1,-1));
            }
        }
    }

    return r;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>>result;
    result=KSmallestPairs({1,2,300},{1,11,20,35,300},30);
    for(auto x: result) {
        for(auto y: x){
            cout << y << ",";
        }
        cout<<endl;
    }
    cout<<endl;
    /* ector<int>>result;
    result=KSmallestPairs({1,1,2},{1,2,3},1);
    for(auto x: result) {
        for(auto y: x){
            cout << y << ",";
        }
        cout<<endl;
    }
    cout<<endl;
    // vector<vector<int>>result;
    result=KSmallestPairs({4,6},{2,3},2);
    for(auto x: result) {
        for(auto y: x){
            cout << y << ",";
        }
        cout<<endl;
    }
    cout<<endl;
    // vector<vector<int>>result;
    result=KSmallestPairs({4,7,9},{4,7,9},5);
    for(auto x: result) {
        for(auto y: x){
            cout << y << ",";
        }
        cout<<endl;
    }
    cout<<endl;
    // vector<vector<int>>result;
    result=KSmallestPairs({1,1,2},{1},4);
    for(auto x: result) {
        for(auto y: x){
            cout << y << ",";
        }
        cout<<endl;
    }
    cout<<endl; */
    return 0;
}

