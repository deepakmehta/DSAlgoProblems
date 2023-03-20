/*
Given a string with matched and unmatched parentheses,
remove the minimum number of parentheses so that the resulting string is a valid parenthesization.

Constraints:
  1<=s.length<=10^5
  s[i]is either (,) or a lowercase letter
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string MinRemoveParentheses(string s) {
    stack<int> st;
    string result("");
    for(auto x:s) {
        if(x==')') {
            if(!st.empty()) {
              st.pop();
              result.push_back(x);
            }
            continue;
        }
        if(x=='(') {
            st.push(result.size());
        }
        result.push_back(x);
    }
    
    while(!st.empty()) {
        result.erase(st.top(),1);
        st.pop();
    }

    return result;
}

int main(){
    // cout << MinRemoveParentheses("()") << endl;
    // cout << MinRemoveParentheses("(") << endl;
    // cout << MinRemoveParentheses(")(") << endl;
    cout << MinRemoveParentheses("ab)ca(so)(sc(s)(") << endl;
    return 0;
}