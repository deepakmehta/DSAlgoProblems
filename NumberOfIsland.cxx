/*
Given an ( m×n ) 2-D binary grid representing a map of 1s and 0s, where 1 represents land and 0 represents water,
we have to return the number of islands.
An island is constructed by linking neighboring areas of land horizontally and vertically.

Constraints:

* The grid only consists of 0s or 1s.
* 1 ≤ grid.length
* grid[i].length ≤ 300
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class UnionFind {
  public:
std::vector < int > parent;
  std::vector < int > rank;
//  int count;
  // Initializing the parent list and count variable by traversing the grid
  UnionFind(std::vector < std::vector < char >>& grid) {
    int m = grid.size(), n = grid[0].size();
  //  count = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          parent.push_back(i * n + j);
          rank.push_back(1);
          //count += 1;
        } else {
          parent.push_back(-1);
          rank.push_back(0);
        }
        
      }
    }
  }
  std::vector < int > GetParent() {
    return parent;
  }

  // Function to find the root parent of a node       
  int Find(int i) {
    if (parent[i] != i && (parent[i]!=-1)) {
      parent[i] = Find(parent[i]);
    }
    return parent[i];
  }

  // Function to connect components
  void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
      //The absolute value of the root node represents the size of this union
      //Make the one with larger size to be the new parent
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
        rank[rootX]+=rank[rootY];
      } 
      else {
        parent[rootX] = rootY;
        rank[rootY] += rank[rootX];
      }
    }
  }
};


int NumIslands(vector<vector<char>> grid)
{  
    UnionFind uf(grid);
    for (int i =0 ; i <grid.size();++i) {
        for (int j=0;j<grid[0].size();++j) {
            if(grid[i][j]=='1') {
                if (j<grid[0].size()-1) {
                    if (grid[i][j+1]=='1') {
                        uf.Union((i*grid[0].size())+j,(i*grid[0].size())+j+1);
                    }
                }
                if (i<grid.size()-1) {
                    if (grid[i+1][j]=='1') {
                        uf.Union((i*grid[0].size())+j,((i+1)*grid[0].size())+j);
                    }
                }
            }
        }
    }   
    int count=0;
    vector<int> parent = uf.GetParent();
    for (int i =0 ; i <parent.size();++i) {
        if (parent[i]==i) count+=1;
    }
    return count;
}

int main() {
    cout << NumIslands({{'1','1','1'},{'0','1','0'},{'1','0','0'},{'1','0','1'}}) << endl;
}