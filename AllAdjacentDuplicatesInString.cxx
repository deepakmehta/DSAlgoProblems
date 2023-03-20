/* 
Given a string consisting of lowercase English letters, repeatedly remove adjacent duplicate letters, one pair at a time.
Both members of a pair of adjacent duplicate letters need to be removed.
Constraints:
1 <=string.length<=10^5
string consists of lower english letter
*/

#include<string>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

string RemoveDuplicates(string toCleanUp) {
     
     stack<char> s;
     for(auto y:toCleanUp) {
        if(!s.empty()) {
            if (s.top()==y) {
                s.pop();
                continue;
            }
        }
        s.push(y);
     }
    string r("");
    while(!s.empty()){
        r+=s.top();
        s.pop();
    }
    reverse(r.begin(),r.end());
    return r;
}

int main(int argc, char const *argv[])
{
    cout <<RemoveDuplicates("g") << endl;
    cout <<RemoveDuplicates("ggaabcdeb") << endl;
    cout <<RemoveDuplicates("abbddaccaaabcd") << endl;
    cout <<RemoveDuplicates("aabbccdd") << endl;
    cout <<RemoveDuplicates("aannkwwwkkkwna") << endl;
    return 0;
}
