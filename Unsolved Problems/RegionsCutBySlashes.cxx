/*
An n×n grid is composed of 1×1 squares, where each 1×1 square consists of a “/”, “\”, or a blank space.
These characters divide the square into contiguous regions.

Given the grid represented as a string array, return the number of contiguous regions.
Note: Backslashes charcaters are escaped, so "\" is represented as "\\".

*/


#include <iostream>
#include <vector>
#include<set>
#include<string>
#include <cstring>

using namespace std;

class UnionFind{
  public:
    std::vector<int> parent;
    set<int> reg;

    UnionFind(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            reg.insert(i);
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void regionUnion(int x, int y){
        int xr = find(x);
        int yr = find(y);
        parent[xr] = yr;
        reg.erase(x);
    }
    int regions(){
        return reg.size();
    }

    void removeEmptyRegions(int x){
        reg.erase(x);
    }
};

void Merge(vector<string>& grid, int r, int c, UnionFind& uf) {
    
    if( grid[r][c]==' ')` {
        uf.removeEmptyRegions((r*grid[0].size())+c); 
        return ;
        }
    if (r-1>0 ) {
        if (grid[r][c]==grid[r-1][c]) {
            uf.regionUnion((r*grid[0].size())+c, ((r-1)*grid[0].size())+c);
        }
    }
    if (c-1>0 ) {
        if (grid[r][c]==grid[r][c-1]) {
            uf.regionUnion((r*grid[0].size())+c, ((r)*grid[0].size())+c-1);
        }
    }
}

int RegionsBySlashes(vector<string> grid)
{  if(!grid.size()) return 0;

    UnionFind uf(grid.size()*grid.size());
    for(int r=0; r<grid.size();++r){
        for(int c=0; c<grid[r].size();++c){
            Merge(grid,r,c ,uf);
        }
    } 
    return uf.regions();
}

int main(int argc, char const *argv[])
{
    //cout << RegionsBySlashes({"/\\","\\/"}) << endl;
     cout << RegionsBySlashes({" /","  "}) << endl;
    // cout << RegionsBySlashes({" /","/ "}) << endl;
    // cout << RegionsBySlashes({"\\\\  /","/\\ //","\\/\\ \\","/\\ /\\","\\////"}) << endl;
    // cout << RegionsBySlashes({"\\\\/\\\\\\ \\"," \\\\//\\/ ","/ / \\\\/\\","\\\\///  \\","/\\\\\\\\/ \\","///////\\","/\\\\// / ","\\///\\\\//"}) << endl;
    return 0;
}
