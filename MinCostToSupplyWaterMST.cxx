/*There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i], or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[i] = [house1, house2, cost] represents the cost to connect house1 and house2 together using a pipe. Connections are bidirectional.

Find the minimum total cost to supply water to all houses.

Example 1:

Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.

Constraints:

1 <= n <= 10000
wells.length == n
0 <= wells[i] <= 10^5
1 <= pipes.length <= 10000
1 <= pipes[i][0], pipes[i][1] <= n
0 <= pipes[i][2] <= 10^5
pipes[i][0] != pipes[i][1]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class edge {

public:
    int n1;
    int n2;
    int cost;
    edge(int a, int b, int c): n1(a), n2(b), cost(c){};
};

class Graph {
public:
   vector<edge> edges;
};

struct sorter {

    bool operator()(const edge& first, const edge& second) {
        if ( first.cost <=second.cost) return true;
        return false;
    }
} sortObj;


class UnionFind {
int* parent;
public:
UnionFind(int v): parent(nullptr) {
  parent = new int(v);
  for ( int i = 0 ; i <v ;++i) {
      parent[i] = -1;  
  }
}

int Uparent(int x) {
    if ( parent[x]==-1) return x;
    return Uparent(parent[x]);
}

bool find(int x, int y) {
     if ( Uparent(x) == Uparent(y)) return true;
     return false;
}

void Myunion( int x, int y) {
   parent[x] = y;
}

};

int main() {
 int numHouses = 3;
 int wells[] = {1,2,2};
 int pipes[][3] = {{1,2,1},{2,3,1}};
 // the problem looks like a graph problem where a pipe represent an edge with a given weight.
 // but the trick is what needs to be done with the cost of creating a well at each vertex
 // If we are to convert this into a MST we have to trick this cost as an edge.
 // we will create a imaginary vertex 0  and connect edges to each house and weight of 
 // each edge will be equal to the cost of wells.
 // than this problem looks like a MST problem with minimum cost for edges.
 // we can use both the approaches to build MST , using the vertex as starting point or
 // edges as starting point.

  /* lets us first create a graph */
  Graph g;
  for ( int i = 0 ; i < 3;++i){
      g.edges.push_back(edge(0, i+1, wells[i]));
  }

  for ( int i = 0 ; i < 2;++i) {
      g.edges.push_back(edge(pipes[i][0], pipes[i][1], pipes[i][2]));
  }

  // lets do the edges way.
  // for this first sort the edges on the basis of cost.
  sort(g.edges.begin(),g.edges.end(), sortObj);
  
  UnionFind uf(4);
  int totalCost = 0;
  for ( auto e : g.edges) {
      if ( uf.find (e.n1,e.n2)) {
       // already part of the MST
      } else {
          uf.Myunion( e.n1, e.n2);
          totalCost+=e.cost;
      }
  }
 std::cout << "Cost: " << totalCost << endl;
 return 0;
}