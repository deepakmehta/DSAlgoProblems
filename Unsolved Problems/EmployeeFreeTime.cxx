/*
You’re given a list containing the schedules of multiple people
Each person’s schedule is a list of non-overlapping intervals in sorted order
An interval is specified with the start time and the end time, both being positive integers
Your task is to find the list of intervals representing the free time for all the people
We’re not interested in the interval from negative infinity to zero or from the end of the last scheduled interval in the input to positive infinity

*/

#include<vector>
#include<iostream>
#include<string>
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

vector<Interval> EmployeeFreeTime(vector<vector<Interval>> schedule)
{
    
    return {};
}

int main(int argc, char const *argv[])
{
    vecor<interval> r;
    r=EmployeeFreeTime({{{1,2},{5,6}},{{1,3}},{{4,10}}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r=EmployeeFreeTime({{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r=EmployeeFreeTime({{{1,2},{3,4},{5,6},{7,8},{9,10},{11,12}},{{1,2},{3,4},{5,6},{7,8},{9,10},{11,12}},{{1,2},{3,4},{5,6},{7,8},{9,10},{11,12}},{{1,2},{3,4},{5,6},{7,8},{9,10},{11,12}}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    r=EmployeeFreeTime({{{1,3},{6,9},{10,11}},{{3,4},{7,12}},{{1,3},{7,10}},{{1,4}},{{7,10},{11,12}}});
    for(auto x: r){
        cout << x.ToString();
    }
    cout << endl;
    return 0;
}
