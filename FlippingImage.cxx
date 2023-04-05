/*
Given an image represented by an (n×n) matrix containing 0s and 1s,
your task is first to flip the image horizontally, then invert it, and return the resultant image.

*/

#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> FlipAndInvertImage(vector<vector<int>> image)
{
    for(int i=0 ; i < image.size();++i){
        for(int j=0; j<(image[0].size()/2);++j){
            swap(image[i][j],image[i][image[0].size()-j-1]);
            
        }
    }
    
    for(int i=0 ; i < image.size();++i){
        for(int j=0; j<image[0].size();++j){
            image[i][j]=image[i][j]?0:1;
        }
    }
    return image;
}

int main(int argc, char const *argv[])
{
    FlipAndInvertImage({{1,1,0},{1,0,1},{0,0,0}});

    return 0;
}
