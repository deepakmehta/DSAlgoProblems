/*
Given a set of n number of tasks, implement a task scheduler method, tasks(), to run in O(n logn) time that
finds the minimum number of machines required to complete these n tasks.

Constraints:
Task start time ≤  Task end time
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int Tasks(vector<vector<int>> tasksList)
{
    //minheap for all the tasks
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;

    for(auto x: tasksList){
        minheap.push(pair<int,int>(x[0],x[1]));
    }
   
   int coresneeded=0;
    priority_queue<int,vector<int>,greater<int>> cores;
    while(!minheap.empty()){
        pair<int,int> task=minheap.top();
        minheap.pop();
        if(cores.empty()) {
          coresneeded++;
          cores.push(task.second);
        } else if (cores.top()>task.first){
            coresneeded++;
            cores.push(task.second);
        } else {
            cores.pop();
            cores.push(task.second);
        }
    }

    return coresneeded;
}

int main(int argc, char const *argv[])
{
    // cout << Tasks({{1, 1}, {5, 5}, {8, 8}, {4, 4}, {6, 6}, {10, 10}, {7, 7}}) << endl;
    // cout << Tasks({{1, 7}, {1, 7}, {1, 7}, {1, 7}, {1, 7}, {1, 7}}) << endl;
    cout << Tasks({{1, 7}, {8, 13}, {5, 6}, {10, 14}, {6, 7}}) << endl;
    cout << Tasks({{1, 3}, {3, 5}, {5, 9}, {9, 12}, {12, 13}, {13, 16}, {16, 17}}) << endl;
    cout << Tasks({{12, 13}, {13, 15}, {17, 20}, {13, 14}, {19, 21}, {18, 20}}) << endl;

    return 0;
}
