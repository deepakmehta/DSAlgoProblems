/*
Given a list of points on a plane, where the plane is a 2-D array with (x, y) coordinates, find the k
 closest points to the origin (0,0).

*/

#include<queue>
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;

class Point {
  public:
    int x;
    int y;
    Point(int X, int Y) {
      // Write your code here
    }
    
    // Write your code here
};

struct cmp {
bool operator()(Point p1, Point p2) const{
    if(( pow(p1.x,2)+pow(p1.y,2))<( pow(p2.x,2)+pow(p2.y,2)))
       return true;
    return false;
}
};

vector<Point> KClosest(vector<Point> locations, int k) 
{
    priority_queue<Point, vector<Point>,cmp> maxheap;
    for(int i=0; i<locations.size();++i){
        if(i<k){
            maxheap.push(locations[i]);
        } else {
            Point top = maxheap.top();
            cmp c;
            if (!c.operator()(top,locations[i])){
              maxheap.pop();
              maxheap.push(locations[i]);
            }
        }
    } 

    vector<Point> ret;
    while(!maxheap.empty()){
        ret.push_back(maxheap.top());
        maxheap.pop();
    }
    return ret;
}