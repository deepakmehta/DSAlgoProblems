/*
We are given an integer number n, representing the number of functions running in a single-threaded CPU,
and an execution log, which is essentially a list of strings.
Each string has the format {function id}:{"start" | "end"}:{timestamp},
indicating that the function with function id either started or stopped execution at time identified by the timestamp value.
Each function has a unique ID between 0 and n−1 . Compute the exclusive time of the functions in the program.

Note: Exclusive time is the sum of the execution times for all the calls to a specific function.

Constraints:
 1<=n<100
 1<=logs.length<=500
 0<=function id<=n
 0<=timestamp<=103
 No two start events and two end events will happen at the same time
 Each function has an end log entry for a start entry

  // looks like a paranthesis problem start reperesent ( and end represent )
*/

#include<regex>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;

void Split(string &s, string &delim, vector<string> &elems)
{
    regex rgx(delim);
    sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    sregex_token_iterator end;
    while (iter != end)
    {
        elems.push_back(*iter);
        ++iter;
    }
}

class Log
{
public:
    int id;
    bool isStart;
    int time;
    Log(string content)
    {
        vector<string> strs;
        string delim = ":";
        Split(content, delim, strs);
        id = stoi(strs[0]);
        isStart = strs[1] == "start";
        time = stoi(strs[2]);
    }
};

// Tip: You may use some of the code templates provided
// in the support files

vector<int> ExclusiveTime(int n, vector<string> logs)
{
    vector<int> results(n,0);
    stack<Log> s;
    //int time_taken_by_others=0;
    for(auto x: logs){
        Log y(x);
        if (y.isStart) {
            s.push(y);
        } else {
            Log z =s.top();
            s.pop();
            if(!(z.id==y.id)) abort();
            results[y.id] += (y.time-z.time+1);
            if (!s.empty()) {   results[s.top().id]-=(y.time-z.time+1); }
            //time_taken_by_others+=(y.time-z.time);
        }
    }
    return results;
}


int main() {
   // vector<int> result = ExclusiveTime(3, {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"});
    
    vector<int>result = ExclusiveTime(1,{"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"});
    for(auto x: result) {
        cout << x << ", ";
    }
    cout << endl;
}