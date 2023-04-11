/*
Given a string, rearrange it so that any two adjacent characters are not the same.
If such a reorganization of the characters is possible, output any possible valid arrangement.
Otherwise, return an empty string.

*/

#include<queue>
#include<string>
#include<iostream>
using namespace std;

string ReorganizeString(string inputString)
{    
    int arr[26]={0};
    for(auto x: inputString){
        arr[x-'a']++;
    }

    priority_queue<pair<int,int>>mheap;
    for(int i=0; i<26;++i){
      if(arr[i]!=0)
      mheap.push(pair<int,int>(arr[i],i));
    }
 
    string result("");
    while(!mheap.empty()){
        pair<int,int> first=mheap.top();
        mheap.pop();
        if(mheap.empty()){
           if(first.first!=1){
            return "";
           } else {
            result+=char(first.second+'a');
            return result;
           }
        }
        pair<int,int> second=mheap.top();
        mheap.pop();
        result+=char(first.second+'a');
        result+=char(second.second+'a');
        if (first.first!=1){
            mheap.push(pair<int,int>(first.first-1,first.second));
        }
        if (second.first!=1){
            mheap.push(pair<int,int>(second.first-1,second.second));
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    cout << ReorganizeString("abb")<<endl;
    cout << ReorganizeString("aaaaabbbbbbb")<<endl;
    cout << ReorganizeString("jjjjj")<<endl;
    cout << ReorganizeString("aaabc")<<endl;
    cout << ReorganizeString("fofjjb")<<endl;
    return 0;
}
