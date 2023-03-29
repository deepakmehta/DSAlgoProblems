/*
You are given an integer array height of length, there are n vertical lines drawn such that the two endpoints of the the ith line are (i,0) 
and (i,height[i]).
Find two lines that, togehter with x-axis form a container that holds as much water as possible.
Return the maximum amount of water a container can store.

*/
#include<vector>
#include<iostream>
using namespace std;

int ContainerWithMostWater(vector<int> height)
{
    if(height.empty() || height.size()==1) return -1;
 int p=0;
    int l=0;
    int r=height.size()-1;
    while(l<r) {
       p=max(p,(r-l)*min(height[l],height[r]));
       if(height[l]<=height[r]) l++;
       else r--;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    cout << ContainerWithMostWater({1,8,6,2,5,4,8,3,7}) << endl;
    cout << ContainerWithMostWater({1,1}) << endl;
    cout << ContainerWithMostWater({2,8,6,3,5,4,7}) << endl;
    cout << ContainerWithMostWater({1,5}) << endl;
    return 0;
}
