/*
Given a string s that represents a DNA sequence, and a number k, return all the contiguous sequences (substrings) of length k that occur more than once in the string. The order of the returned subsequences does not matter.
If no repeated subsequence is found, the function should return an empty set.



*/

#include<string>
#include<set>
#include<map>
#include<iostream>

using namespace std;


set<string> FindRepeatedSequences(string s, int k)
{
    map<string,int> hashtofreqmap_;
set<string>dummy{};
    int ws=0; //int we=0;
    for(int we=0; we<s.size();++we) {
       //we++;
       if(we-ws==k-1) {
        
        if(hashtofreqmap_.find(s.substr(ws,k))!=hashtofreqmap_.end()){
            hashtofreqmap_[s.substr(ws,k)]=++hashtofreqmap_[s.substr(ws,k)];
        } else {
hashtofreqmap_[s.substr(ws,k)]=1;
        }
        ws++;
       }
    }
    for(auto x: hashtofreqmap_) {
        if (x.second>1) {
            dummy.insert(x.first);
        }
    }
    return dummy;
}

int main() {
    set<string>result;
    result=FindRepeatedSequences("AAAAACCCCCAAAAACCCCCC",8);
    for (auto x:result)
    {
        cout<< x << " ," ;
    }
    cout << endl;
    result=FindRepeatedSequences("GGGGGGGGGGGGGGGGGGGGGGGGG",12);
    for (auto x:result)
    {
        cout<< x << " ," ;
    }
    cout << endl;
    result=FindRepeatedSequences("TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT",10);
    for (auto x:result)
    {
        cout<< x << " ," ;
    }
    cout << endl;
    result=FindRepeatedSequences("AAAAAACCCCCCCAAAAAAAACCCCCCCTG",10);
    for (auto x:result)
    {
        cout<< x << " ," ;
    }
    cout << endl;
    result=FindRepeatedSequences("ATATATATATATATAT",6);
    for (auto x:result)
    {
        cout<< x << " ," ;
    }
    cout << endl;
    return 0;
}