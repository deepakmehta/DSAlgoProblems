/*
You’re given an array of non-overlapping intervals, and you need to insert another interval into the array.
Each interval is a pair of non-negative numbers, the first being the start time and the second being the end time of the interval.
The input array of intervals is sorted in ascending order of start time.

The intervals in the output must also be sorted by the start time, and none of them should overlap.
This may require merging those intervals that now overlap as a result of the addition of the new interval.


*/
#include<string>
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
        return (this->closed) ? "{" + std::to_string(this->start) + ", " + std::to_string(this->end) + "}" : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};



// Function that inserts the respective interval
vector<Interval> InsertInterval(vector<Interval> existingIntervals, Interval newInterval)
{
    /*if(!existingIntervals.size()) {
        return vector<Interval>(1,newInterval);
    }*/
int i=0;
    for( ;i<existingIntervals.size();++i){
        if (existingIntervals[i].end<newInterval.start) continue;

        if( existingIntervals[i].start>newInterval.start) {
            existingIntervals[i].start=newInterval.start;
        }
        if( existingIntervals[i].end<newInterval.end){
            existingIntervals[i].end=newInterval.end;
        }
        break;
    }
    if( i==existingIntervals.size()){
        existingIntervals.push_back(newInterval);
    }

    vector<Interval> returnVec;
    returnVec.push_back(existingIntervals[0]);
    for(int i=1; i<existingIntervals.size();++i){
        if( returnVec.back().end<existingIntervals[i].start){
            returnVec.push_back(existingIntervals[i]);
        } else {
            if(returnVec.back().start>existingIntervals[i].start){
                returnVec.back().start=existingIntervals[i].start;
            }
            if(returnVec.back().end<existingIntervals[i].end){
                returnVec.back().end=existingIntervals[i].end;
            }
        }
    }
    return returnVec;
}

int main()
{
    vector<Interval> r;

    r= InsertInterval({{1,2},{3,4},{5,8},{9,15}},{2,5});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    r= InsertInterval({{1,6},{8,9},{10,15},{16,18}},{9,10});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    r= InsertInterval({{1,2},{3,4},{5,8},{9,15}},{16,17});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    r= InsertInterval({{1,4},{5,6},{7,8},{9,10}},{1,5});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    r= InsertInterval({{1,3},{4,6},{7,8},{9,10}},{1,10});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    r= InsertInterval({{1,2},{3,4},{5,6},{7,8},{9,10}},{3,5});
    for(auto x: r){
        cout << x.ToString() ;
    }
    cout << endl;
    return 0;
}
