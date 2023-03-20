/*
For a given number, n, generate all combinations of balanced parentheses.
Constraints:
1 ≤  n ≤8
*/

#include <vector>
#include <string>
#include<iostream>
using namespace std;

void GenCombination(string curr, int ob, int eb, int n, vector<string> &r)
{
    if (eb == n)
    {
        r.push_back(curr);
        return;
    }
    if (ob < n)
    {
        string openbracketadded = curr + "(";
        GenCombination(openbracketadded, ob + 1, eb, n,r);
    }
    if (eb < ob)
    {
        string closebracketadded = curr + ")";
        GenCombination(closebracketadded, ob, eb + 1, n,r);
    }
}

vector<string> GenerateCombinations(int n)
{
    vector<string> r;
    string intermediate("");
    int ob = 0;
    int eb = 0;
    GenCombination(intermediate, ob, eb, n, r);
    return r;
}

int main() {
    vector<string> r;
    r=GenerateCombinations(2);
    for(auto x:r){
        cout << x << ",";
    }
    cout<<endl;
    r=GenerateCombinations(4);
    for(auto x:r){
        cout << x << ",";
    }
    cout<<endl;
}