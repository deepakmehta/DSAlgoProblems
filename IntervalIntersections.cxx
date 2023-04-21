/*
For two lists of closed intervals given as input, intervalListA and intervalListB,
where each interval has its own start and end time, write a function that returns the intersection of the two interval lists.

For example, the intersection of {3,8} and  {5,10} is {5,8}.

*/

#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Interval
{
public:
    int start, end;
    bool closed;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
        this->closed = true; // by default, the interval is closed
    }
    // set the flag for closed/open
    void SetClosed(bool closed)
    {
        this->closed = closed;
    }
    std::string ToString()
    {
        return (this->closed) ? "{" + std::to_string(this->start) + ", " + std::to_string(this->end) + "}" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};

vector<Interval> IntervalsIntersection(vector<Interval> intervalListA, std::vector<Interval> intervalListB)
{
    vector<Interval> dummyResult;
    int itema=0;
    int itemb=0;
    while(itema<intervalListA.size() && itemb <intervalListB.size()){
        
        Interval a=intervalListA[itema];
        Interval b=intervalListB[itemb];
        if (a.end < b.start){
            // no merge
            itema++;
            continue;
        } else if (b.end<a.start){
            // no merge
            itemb++;
            continue;
        } else {
            // merge case
            dummyResult.push_back(Interval(max(a.start,b.start),min(a.end,b.end)));
            if(a.end<b.end){
                itema++;
            } else {
                itemb++;
            }
        }
    }   
    return dummyResult; 
}

int main()
{
    vector<Interval> r;
    r= IntervalsIntersection({{1,4},{5,6},{7,8},{9,15}},{{2,4},{5,7},{9,15}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r= IntervalsIntersection({{1,3},{4,6},{8,10},{11,15}},{{2,3},{10,15}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r= IntervalsIntersection({{1,2},{4,6},{7,8},{9,10}},{{3,6},{7,8},{9,10}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r= IntervalsIntersection({{1,3},{5,6},{7,8},{9,10},{12,15}},{{2,4},{7,10}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r= IntervalsIntersection({{1,2}},{{1,2}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    return 0;
}
