/*
We’re given a graph that is actually a tree with n  nodes labeled from 1 to n
, plus one additional edge. The additional edge connects two different vertices and is not a duplicate of an existing edge.

The graph is represented as an array called edges of length n where edges[i] = [a, b] indicates that there is an edge between nodes a and b in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple candidates for removal, return the edge that occurs last in edges.

Constraints:

* n=edges.length
* 3≤ n ≤1000
* edges[i].length =  2
* 1≤a <b ≤ ≤n
* a !=b
* There are no repeated edges.
* The given graph is connected.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UnionFind
{
public:
    std::vector<int> parent;
    std::vector<int> rank;

    UnionFind(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int FindParent(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = FindParent(parent[x]);
        }
        return parent[x];
    }

    bool Union(int v1, int v2)
    {
        int p1 = FindParent(v1);
        int p2 = FindParent(v2);
        if (p1 == p2)
        {
            return false;
        }
        else if (rank[p1] < rank[p2])
        {
            parent[p2] = p1;
            rank[p2] += rank[p1];
        }
        else
        {
            parent[p1] = p2;
            rank[p1] += rank[p2];
        }
        return true;
    }
};

vector<int> RedundantConnections(vector<vector<int>> edges)
{
    vector<int> result;
    UnionFind uf(edges.size());
    for (auto y : edges)
    {
        int f = y[0];
        int s = y[1];

        if (!uf.Union(f, s))
        {
            result.push_back(f);
            result.push_back(s);
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> result = RedundantConnections({{1, 2}, {1, 3}, {2, 3}});
    for (auto x : result)
    {
        cout << x << endl;
    }
}