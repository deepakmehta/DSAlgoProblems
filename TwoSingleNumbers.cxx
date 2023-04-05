/*
Given a non-empty array arr, in which exactly two elements appear once and all the other elements appear twice,
return the two elements that come only once.
Note: The result can be returned in any order, the solution uses constant space

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> TwoSingleNumbers(vector<int> lists)
{
    if(!lists.size()) return {};
    int xortwoNum=0;
    for(auto x: lists) {
        xortwoNum^=x;
    }
    
    cout << "xor: " << xortwoNum << endl;
    // Lets compute the left most 1st bit;
    //int temp=xortwoNum;
    //int leftmostbit=0;
    int i=0;
    for(; i < sizeof(int)*8;++i){
        if(xortwoNum&(1<<i)) break;
    }
    cout << " i: " << i << endl;
    int firstNum=0;
    for(auto x: lists) {
       if(x&(1<<i)) {
         cout << "xor with:" << x <<endl;
         firstNum^=x;
       } 
    }
    vector<int> result;
    result.push_back(firstNum);
    result.push_back(xortwoNum^firstNum);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> r;
    r= TwoSingleNumbers({1,1,2,3,4,3});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
