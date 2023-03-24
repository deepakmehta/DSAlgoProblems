/*
Given an array of integers, heights, which represents the histogram’s bar height, find the area of the largest rectangle in the histogram, where the width of each bar is constant (such as, 1).
Constraints
1<=heights<=10^5
0<=hieghts[i] <=10^4
*/

#include<stack>
#include <vector>
#include <iostream>
using namespace std;

int LargestRectangle(vector<int> heights)
{
    stack<int> s;
    //s.push(-1);
    // Next Greater element
    // for each height lets compute the number of cells to the left untill we see a height less than it
    vector<int> leftIndex(heights.size(), 0);
    //leftIndex[0]=0;
    for(int i=0; i<heights.size();++i) {
        if (s.empty()) {
                     s.push(i);
                     leftIndex[i]=0;
                     continue;
        }

        if (heights[i]>heights[s.top()]) {
            s.push(i);
            leftIndex[i]=0;
        } else {
            while(!s.empty()&& heights[i]<=heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) { 
                leftIndex[i]=(i-s.top()-1);
            } else {
                leftIndex[i]=i-0;
            }
            s.push(i);
        }
    }

    while(!s.empty()) s.pop();
    // for each height lets compute the number of cells to the right untill we see  height less than it.
    vector<int> rightIndex(heights.size(), 0);
    
    rightIndex[heights.size()-1]=0;
    for(int i=heights.size()-1; i>=0;--i) {
        if (s.empty()) {
            s.push(i);
            rightIndex[i]=0;
            continue;
        }
        if (heights[i]>heights[s.top()]) {
            s.push(i);
            rightIndex[i]=0;
        } else {
            while(!s.empty()&& heights[i]<=heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) { 
                rightIndex[i]=(s.top()-i-1);
            } else {
                rightIndex[i]=heights.size()-i-1;
            }
            s.push(i);
            
            //rightIndex[i]=rightIndex[i-1]+1;
        }
    }
// for each height compute the biggest rectangle possible (right(hi)-left(hi)+1)*hi
    int lr = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
       // cout << "h: " << heights[i] << " li: " << leftIndex[i] << " ri: " << rightIndex[i] << endl;
        lr = max(lr, heights[i] * (rightIndex[i] + leftIndex[i] + 1));
    }
    return lr;
}

int main()
{
    //cout << LargestRectangle({6, 2, 5, 4, 5, 1, 6, 4, 2}) << endl;
    cout << LargestRectangle({3, 5}) << endl;
    // cout << LargestRectangle({1, 2, 3, 4, 5, 2, 1, 3, 5, 2}) << endl;
    // cout << LargestRectangle({0, 0, 0}) << endl;
}