/*
We’re given an array of closed intervals as input where each interval has a start and end timestamp.
The input array is sorted by starting timestamps.
Merge the overlapping intervals and return a new output array.

Constraints:
 * 1<=intervals.length<=10^4
 * intervals[i].length<=2
 * 0<=starttime<=endtime<=10^4
 
*/
#include<vector>
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
        return (this->closed) ? "[" + std::to_string(this->start) + ", " + std::to_string(this->end) + "]" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};

vector<Interval> MergeIntervals(vector<Interval> intervals)
{
    
}

int main(){
    vector<Interval> i;
    i=MergeIntervals({{1,5},{3,7},{4,6}});
    for(auto x: i) {
        cout<< x.ToString() << "," ;
    }
    cout<<endl;
    i=MergeIntervals({{1,5},{4,6},{6,8},{11,15}});
    for(auto x: i) {
        cout<< x.ToString() << "," ;
    }
    cout<<endl;
    i=MergeIntervals({{3,7},{6,8},{10,12},{11,15}});
    for(auto x: i) {
        cout<< x.ToString() << "," ;
    }
    cout<<endl;
    i=MergeIntervals({{1,9},{3,8},{4,4}});
    for(auto x: i) {
        cout<< x.ToString() << "," ;
    }
    cout<<endl;
}