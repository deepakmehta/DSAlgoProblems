
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool valid(string segment){
    // check only for 3 dots
    // each number should be in range 0-255
    // Do we need to check for negative numbers
    
    size_t last_dot_position=0;
    int numberdots=3;
    while(numberdots>0) {
      size_t dot_found = segment.find('.',last_dot_position);
      if (dot_found!=string::npos) {
        // lets get string
        string sub_str = segment.substr(last_dot_position,dot_found);
        numberdots--;
        last_dot_position=dot_found+1;
        if (sub_str.empty() || (atoi(sub_str.c_str()) >255)) return false;
      } else { 
      return false;
      }  
    }


    if ( (numberdots>0) ||
         ( segment.find('.',last_dot_position)!=string::npos)) {
            return false;
    }
   
    // lets also check the last element
        string sub_str = segment.substr(last_dot_position);
        if (sub_str.empty() || (atoi(sub_str.c_str()) >255)) return false;
        // if (atoi(sub_str.c_str()) >255) return false;

    return true;
}

// // This function will append the current list of segments to the list of result
// void updateSegment(string s, int currPos, vector<string>& segments,
//  vector<string>& result){

//     // Write your code here
// }

void backtrack(string& s, int prevpos, int dots,  vector<string>& result){
    if (dots==0) {
        if (valid(s)) result.push_back(s);
        return;
    }

    for (int i=prevpos; (i<prevpos+3) && i<s.length();++i) {
        s.insert(i+1,".");
        backtrack(s,i+2,dots-1,result);
        s.erase(i+1,1);
    }
}

vector<string> restoreIpAddresses(string s){
    vector<string> result;
    backtrack(s,0,3,result);
    return result;
}

int main() {
    vector<string>result = restoreIpAddresses("12121212");
    for(auto x: result) {
        cout << x << endl;
    }
    // cout << "valid check: " << valid("12.12.12.12") << endl; 
    // cout << "valid check: " << valid("0.12.12.12") << endl;
    // cout << "valid check: " << valid("12.12.12") << endl;
    // cout << "valid check: " << valid("12.12.12.12.12") << endl;
    // cout << "valid check: " << valid("12.12.12.258") << endl;
    return 0;
}