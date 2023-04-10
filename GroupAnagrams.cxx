/*
Given a list of words or phrases, group the words that are anagrams of each other.
An anagram is a word or phrase formed from another word by rearranging its letters.

Constraints:

Let strs be the list of strings given as input to find the anagrams.

1≤strs.length ≤10^4
 0≤strs[i].length ≤100
strs[i] consists of lowercase English letters.

*/
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

void GroupAnagrams(vector<string>& strs, vector<vector<string>> &groups){
    map<vector<int>,vector<string>> m;
    for(auto x: strs){
        vector<int> freq(26,0);
        for(auto y: x){
              freq[y-'a']++; 
        }
        if(m.find(freq)!=m.end()){
            m[freq].push_back(x);
        } else {
            m.insert(pair<vector<int>,vector<string>>(freq,vector<string>(1,x)));
        }
    }
    //vector<vector<string>> r;
    for(auto x: m) {
         groups.push_back(x.second);
    }    
    //return r;
}

int main(int argc, char const *argv[])
{
    vector<string> x({"eat","tea","tan","ate","nat","bat"});
    vector<vector<string>> r;
    GroupAnagrams(x, r);
    for(auto x: r) {
        for(auto y:x) {
            cout << y << ",";
        }
        cout << endl;
    }
    return 0;
}
