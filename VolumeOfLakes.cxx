/*
Imagine an island that is in the shape of a bar graph
When it rains, certain areas of the island fill up with rainwater to form lakes
Any excess rainwater the island cannot hold in lakes will run off the island to the west or east and drain into the ocean

Given an array of positive integers representing 2-D bar heights, design an algorithm (or write a function) that can compute the total volume (capacity) of water that could be held in all lakes on such an island given an array of the heights of the bars
Assume an elevation map where the width of each bar is 1

Example: Given [1,3,2,4,1,3,1,4,5,2,2,1,4,2,2],
return 15 (3 bodies of water with volumes of 1,7,7 yields total volume of 15)

*/

#include<vector>
#include<iostream>
using namespace std;

int LakeVolume(vector<int>bars){
    vector<pair<int,int>>leftrightHeights(bars.size(),pair<int,int>(0,0));
    int left=0;
    for(int i=0; i<bars.size();++i){
        leftrightHeights[i].first=left;
        if (bars[i]>left) {
            left=bars[i];
        }
    }

    int right=0;
    for(int i=bars.size()-1; i>=0;--i){
        leftrightHeights[i].second=right;
        if (bars[i]>right) {
            right=bars[i];
        }
    }

int vol=0;
    for(int i=0;i<bars.size();++i){
        int minheight=min(leftrightHeights[i].first,leftrightHeights[i].second);
        if(bars[i]<minheight){
           vol+=(minheight-bars[i]);
        }
    }
    return vol;
}

int main(int argc, char const *argv[])
{
    vector<int>bargraph{1,3,2,4,1,3,1,4,5,2,2,1,4,2,2};
    cout << LakeVolume(bargraph) << endl;
    return 0;
}
