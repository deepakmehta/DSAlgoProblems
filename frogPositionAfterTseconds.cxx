
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void recurse(int n, vector<vector<int>>& edges, int t, int target, int curr, double& ans, double& prob) {
        int numElements = edges[curr-1].size(); 
        if ( target == curr) {
            if ( (t == 0) 
                ||( numElements==0)) {
                ans=prob;
                return;
            } 
          return;    
        }
        
        if (numElements>=0) {
            for ( auto e: edges[curr-1]) {
                double p = ((double)1/(double)numElements);
                p *= prob;
              recurse(n, edges,t, target,e,ans,p);   
            }
        }
        
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        double prob = 1.0;
        double ans=0.0;
        recurse( n, edges, t, target, 1, ans,prob);
        return ans;
    }
};


int main(){

    vector<vector<int>> edges{{2,3,4},{4,6},{5},{},{},{},{}};
    Solution s;
     cout << s.frogPosition(7,edges, 2, 4) << endl;
    return 0;
}