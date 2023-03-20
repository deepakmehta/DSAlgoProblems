/*

Given a set of integers, find all possible subsets within the set.
Note:  The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:
1<=set.length<=10
-10<=set[i]<=10
All numbers of set are unique

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> FindAllSubsets(vector<int> v)
{
    vector<vector<int>> x;
    x.push_back(vector<int>());
    for(auto val: v) {
        int currsize=x.size();
        for(int j=0; j<currsize;++j){
            x.push_back(x[j]);
        }
        //cout<<"double size: " << x.size() << endl;
        for(int i=currsize;i<x.size();++i){
            x[i].push_back(val);
        }
    }
    return x;
}

int main(int argc, char const *argv[])
{
     vector<vector<int>> r;
    // r=FindAllSubsets({1});
    // for(auto x: r){
    //     cout<<"[ " ;
    //     for(auto y: x) {
    //         cout<< y <<" ,";
    //     }
    //     cout<< " ],"; 
    // }
    // cout<<endl;
r=FindAllSubsets({1,2});
for(auto x: r){
    cout<<"[ " ;
    for(auto y: x) {
        cout<< y <<",";
     }
    cout<< " ],"; 
}
cout<<endl;
// r=FindAllSubsets({2,5,7});
// for(auto x: r){
//     cout<<"[ " ;
//     for(auto y: x) {
//         cout<< y <<",";
//      }
//     cout<< " ],"; 
// }
// cout<<endl;
// r=FindAllSubsets({1,2,3,4});
// for(auto x: r){
//     cout<<"[ " ;
//     for(auto y: x) {
//         cout<< y <<",";
//      }
//     cout<< " ],"; 
// }
// cout<<endl;
// r=FindAllSubsets({0});
// for(auto x: r){
//     cout<<"[ " ;
//     for(auto y: x) {
//         cout<< y <<",";
//      }
//     cout<< " ],"; 
// }
// cout<<endl;
// r=FindAllSubsets({7,3,1,5});
// for(auto x: r){
//     cout<<"[ " ;
//     for(auto y: x) {
//         cout<< y <<",";
//      }
//     cout<< " ],"; 
// }
// cout<<endl;
// r=FindAllSubsets({-1,-10,-3,1,2,4});
// for(auto x: r){
//     cout<<"[ " ;
//     for(auto y: x) {
//         cout<< y <<",";
//      }
//     cout<< " ],"; 
// }
// cout<<endl;
    return 0;
}
