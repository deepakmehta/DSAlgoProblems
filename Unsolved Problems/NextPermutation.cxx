#include<vector>
#include<iostream>

using namespace std;

void nextPermutation(vector<int> &p, int n)
{
    //  Write your code here.
    int pos = n-1;
    int elem = p[pos];
    for(int i=n-2; i>=0; i--)
    {
        if(p[i]<elem)
        {
            pos = i;
            break;
        }
    }
    if(pos == n-1)
    {
        for(int i=1; i<=n; i++)
            p[i-1]=i;
        return ;
    }
    p.insert(p.begin()+pos, elem);
    p.pop_back();
    return ;
}

void printVec(vector<int>p){
    cout<<"{";
    for(auto x: p) {
        cout<< x << ",";
    }
    cout<<"}";
}

int main() {
    vector<int> p{1,2,3,4,5};
    for(int i=0; i<100;++i){
        nextPermutation(p,5);
        printVec(p);
    }
}