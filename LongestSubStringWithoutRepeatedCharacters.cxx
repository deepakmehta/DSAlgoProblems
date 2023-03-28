/*
Given a string, find the longest substring without repeating characters, and return the length of that longest substring.
Constraints:
* 1<=input.length<5*10^4
* The string consists of English Letters, Digit, symbols and spaces
*/

#include<string>
#include<set>
#include<iostream>
using namespace std;

int FindLongestSubstring(string inputString){
   set<char> s_;
   int ls=0;
   int ws=0;
   int we=0;
   for(; we <inputString.size();++we) {
    if(s_.find(inputString[we])==s_.end()){
        s_.insert(inputString[we]);
    } else {
        // first repating character
        ls=max(ls,we-ws);
        // lets move the ws ahead
        while(inputString[ws++]!=inputString[we]){
            s_.erase(inputString[ws-1]);
            //ws++;
        }
    }
   }
   ls=max(ls,we-ws);
return ls;
   
}

int main(int argc, char const *argv[])
{
    cout << FindLongestSubstring("abcdbea") << endl;
    cout << FindLongestSubstring("abccabcabcc") << endl;
    return 0;
}
