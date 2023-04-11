/*
Given an infinite stream of integers, nums, design a class to find the kth largest element in a stream.
Note: It is the kth largest element in the sorted order, not the kth distinct element.

The class should have the following functions, inputs, and return values:

*/
#include<queue>
using namespace std;

class KthLargest{
    public:
    int k;
    priority_queue<int, vector<int>, greater<int>> queue; 
    // constructor to initialize heap and add values in it
    KthLargest(int K, vector<int> nums):k(K){

        for(int i=0 ; i<nums.size();++i){
            if (queue.size()<k){
                queue.push(nums[i]);
            } else {
                if (num[i]>queue.top()){
                    queue.pop();
                    queue.push(nums[i]);
                }
            }
        }
    }

    // adds element in the heap
    int add(int val){
        if (queue.size()<k){
                queue.push(val);
            } else {
                if (val>queue.top()){
                    queue.pop();
                    queue.push(val);
                }
            }
        return queue.top();
    }

    // returns kth largest element from heap
    int ReturnKthLargest(){
        if(q.size()<k) return -1;
        return queue.top();
    }
};