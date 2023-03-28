/*
Given a string array, words, and an integer k, return the k most frequent strings.
Sort the frequencies from highest to lowest and then return the top k
frequent words. Words with the same frequency should be sorted by their lexicographical order.

Constraints:
 1 <=words.length<=500
 1<=words[i].length<=10
 words[i] consists of lowercase english letters
 K in the range [1, unique words[i]]

*/

#include <vector>
#include <iostream>
#include<map>
#include<string>
#include<list>
#include<algorithm>

using namespace std;


vector<string> TopKFrequentWords(vector<string> words, int k)
{
   vector<pair<int, string>> vp;
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            vp.push_back({it.second, it.first});
        }
        
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(begin(vp), end(vp), lambda);
        
        int i = 0;
        vector<string> result(k);
        while(i < k) {
            result[i] = vp[i].second;
            i++;
        }
        
        return result;
}


int main(){
    vector<string> r;
    r=TopKFrequentWords({"lets","play","cricket","and","then","lets","play","badminton"},3);
    for(auto x: r) {
        cout << x << ", ";
    }
    cout << endl;
    r=TopKFrequentWords({"for","every","action","there","is","an","equal","but","opposite","reaction"},2);
    for(auto x: r) {
        cout << x << ", ";
    }
    cout << endl;
    r=TopKFrequentWords({"where","there","is","a","will","there","is","a","way"},3);
    for(auto x: r) {
        cout << x << ", ";
    }
    cout << endl;
    r=TopKFrequentWords({"fear","leads","to","anger","anger","leads","to","hatred","hatred","leads","to","conflict","conflict","leads","to","suffering"},7);
    for(auto x: r) {
        cout << x << ", ";
    }
    cout << endl;
}