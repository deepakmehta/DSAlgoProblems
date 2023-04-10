/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences in any order.

Note: The same word in the dictionary may be reused multiple times in the segmentation.

*/

#include<vector>
#include<iostream>
#include<set>
using namespace std;

vector<string> WordBreak(string s, vector<string> wordDict)
{

    vector<vector<string>>dp(s.size(),vector<string>());
    size_t maxlength=0;
    set<string> dict;
    for(auto x: wordDict){
      dict.insert(x);
      maxlength=max(maxlength,x.size());
    }

    for(int ew=0; ew<s.size();++ew){
        int sw=ew;
        while( (ew-sw<maxlength) && sw>=0){
            //cout << "String searched: " << s.substr(sw,ew-sw+1) << endl;
            if (dict.find(s.substr(sw,ew-sw+1))!=dict.end()){
                if (sw==0) {
                    dp[ew].push_back(s.substr(sw,ew-sw+1));
                } else {
                    for(auto x: dp[sw-1]){
                        string push=x;
                        push+=" ";
                        push+=s.substr(sw,ew-sw+1);
                        dp[ew].push_back(push);
                    }
                }
            }
            sw--;
        }
    }

    return dp[s.size()-1];
}

int main(int argc, char const *argv[])
{
    vector<string>r;
    r = WordBreak("magiclly",{"ag","al","icl","mag","magic","ly","lly"});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    r = WordBreak("raincoats",{"rain","oats","coat","s","rains","oat","coats","c"});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    r = WordBreak("highway",{"crash","cream","high","highway","low","way"});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    r = WordBreak("robocat",{"rob","cat","robo","bo","b"});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    r = WordBreak("cocomomo",{"co","mo","coco","momo"});
    for(auto x: r) {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
