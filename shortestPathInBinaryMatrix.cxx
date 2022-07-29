#include <iostream>
#include<vector>
#include<queue>
#include<utility>
#include<set>
using namespace std;

struct compare {
bool operator()( const pair<int,pair<int, int>>& x, const pair<int, pair<int,int>>& y) {
    if ( x.first > y.first) return true;
    return false;
}
};

struct cmpSet{
bool operator()(const pair<int,int>& x, const pair<int,int>& y) {
    if ( x.first< y.first) return true;
    if (x.second < y.second) return true;
    return false;
}
};
class Solution {
    
public:
    
    void updateDistance(priority_queue< pair<int, pair<int,int>>,
                          vector< pair<int, pair<int,int>>>,
                          compare>& q ,int inc_r, int inc_c,int r, int c,
                          const pair<int,pair<int,int>> curr,
                          const vector<vector<int>>& grid ) {
        
        if ( (curr.second.first +inc_r <0) || (curr.second.first +inc_r >=r)) return;
        if ( (curr.second.second +inc_c <0) || (curr.second.first +inc_c >=c)) return;
        // lets update the distance
        int new_dist = curr.first+1;
        //vector<vector<int>>& grid
        if (grid[curr.second.first+inc_r][curr.second.second+inc_c]==0) {
            q.push( make_pair(new_dist,make_pair(curr.second.first+inc_r, curr.second.second+inc_c)));
        }
    }
    
    bool isVisited(const pair<int, int>& a, set<int>& visited, int r, int c ) {
        if ( visited.find(a.first*r+a.second) == visited.end()) return false;
        return true;
    }
    
    void SetVisited(const pair<int, int>& x, set<int>& visited, int r, int c) {
        visited.insert(x.first*r + x.second);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        // priority_queue
        priority_queue< pair<int, pair<int,int>>,vector< pair< int,pair<int,int>>>,compare> q;
        set<int> visited;
        q.push(make_pair(1,make_pair(0,0)));
        
        while (!q.empty()) {
            const pair<int,pair<int,int>>   curr = q.top();
            q.pop();
            //if (visited.find(curr.second) == visited.end()) {
            if (!isVisited(curr.second,visited, r, c)){
                // element not found
                SetVisited(curr.second, visited, r, c);
                if (( curr.second.first == r-1) && (curr.second.second==c-1)) {
                    return curr.first;
                } 
                    // lets do bst
                    updateDistance(q,1,0,r,c,curr,grid);
                    updateDistance(q,1,1,r,c,curr,grid);
                    updateDistance(q,0,1,r,c,curr,grid);
                    updateDistance(q,-1,0,r,c,curr,grid);
                    updateDistance(q,-1,-1,r,c,curr,grid);
                    updateDistance(q,0,-1,r,c,curr,grid);
                    updateDistance(q,1,-1,r,c,curr,grid);
                    updateDistance(q,-1,1,r,c,curr,grid);
            }
        }
        return 0;
    }
};

int main() {
  
//   vector<vector<int>> x({{1,0,0},{1,1,0},{1,1,0}});
//   vector<vector<int>> x({{0,1},{1,0}});
vector<vector<int>> x({{0,0,0,0},{1,0,0,1},{0,1,0,0},{0,0,0,0}});
  Solution y;
  std::cout << y.shortestPathBinaryMatrix(x ) << std::endl;
}