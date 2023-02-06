#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void recurseIsland(queue<pair<int, int>>& currIsland, pair<int,int> entry,
vector<vector<int>>& grid) {
    if( entry.first==-1 
       || entry.second==-1 
       || entry.first>=grid.size()
       ||entry.second>=grid.size()) {
           return;
    }
    if (grid[entry.first][entry.second]==1) {
        currIsland.push(entry);
        grid[entry.first][entry.second]=-1;
        recurseIsland(currIsland,pair<int,int>(entry.first-1,entry.second),grid);
        recurseIsland(currIsland,pair<int,int>(entry.first+1, entry.second),grid);
        recurseIsland(currIsland,pair<int,int>(entry.first,entry.second-1), grid);
        recurseIsland(currIsland,pair<int,int>(entry.first,entry.second+1),grid);
    }
}

bool expandrecurseIsland(queue<pair<int, int>>& currIsland, pair<int,int> entry,
vector<vector<int>>& grid) {
    if( entry.first==-1 
       || entry.second==-1 
       || entry.first>=grid.size()
       ||entry.second>=grid.size()) {
           return false;
    }

    if (grid[entry.first][entry.second]==1) {
      //  cout << "found another island at: " << entry.first << " , " << entry.second << endl;
        return true;
    }

    if (grid[entry.first][entry.second]==0) {
        currIsland.push(entry);
        grid[entry.first][entry.second] = -1;
        return false;
    }
return false;
}

bool expandAndCheckforAnotherIsland(queue<pair<int,int>>& currIsland, vector<vector<int>>&grid,int i) {
    // currElement
    pair<int,int> entry = currIsland.front();
    //cout << "Checking for another island near by: " << entry.first << ", "  << entry.second << endl;
    currIsland.pop();
    return expandrecurseIsland(currIsland,pair<int,int>(entry.first-1,entry.second),grid) ||
           expandrecurseIsland(currIsland,pair<int,int>(entry.first+1, entry.second),grid) ||
           expandrecurseIsland(currIsland,pair<int,int>(entry.first,entry.second-1), grid) ||
           expandrecurseIsland(currIsland,pair<int,int>(entry.first,entry.second+1),grid);
}

void dumpGrid( vector<vector<int>>& grid) {
    for ( int i = 0; i < grid.size();++i) {
        for (int j=0 ; j<grid[0].size();++j){
            cout << grid[i][j] << " ,";
        }
    }
    cout << endl;
} 

int shortestBridge(vector<vector<int>>& grid)
{
    queue<pair<int,int>> currIsland;
  
    pair<int,int> firstEntry;

    for ( int i = 0; i < grid.size();++i) {
        for (int j=0 ; j<grid[0].size();++j){
            if (grid[i][j]==1) {
                 firstEntry=pair<int,int>(i,j);
                 break;
            }
        }
    }

    // lets get the current island

    recurseIsland(currIsland,firstEntry,grid);

   // dumpGrid(grid);

    // Lets do depth first
    int depth=0;
    bool nextIslandFound=false;
    for ( int k = 0 ; (k <2*grid.size())&&!nextIslandFound;++k) {
    int len=currIsland.size();
    //cout << " Current queue size" << len << endl;
    for ( int i = 0; i <len;++i) {
        nextIslandFound = expandAndCheckforAnotherIsland(currIsland,grid,i);
        if (nextIslandFound) return depth;
    }
    //dumpGrid(grid);
        depth++;
    }
    return depth ;
}


int main() {
    //vector<vector<int>> abc {{0,1,1},{1,0,1},{1,0,1}};
    vector<vector<int>> abc {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
    cout << shortestBridge(abc) << endl;
    //{{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}}
}
