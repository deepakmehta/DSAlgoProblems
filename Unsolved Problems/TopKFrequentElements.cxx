#include<vector>
#include <iostream>

using namespace std;

vector<int> TopKFrequent(vector<int> lists, int k)
{
    
    
    return {};
}

void dumpVec(vector<int> v) {
    for (auto a: v) {
      cout << a << " , ";
    }
}

int main() {
    int k =10;
    vector<int> input{3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    dumpVec(TopKFrequent(input,k)); cout << endl;
    input=vector<int>{5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5};
    k=7;
    dumpVec(TopKFrequent(input,k)); cout << endl;
    return 0;
}