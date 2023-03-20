/*
You’re given an array, people, where people{i} is the weight of the ithperson,
and an infinite number of boats, where each boat can carry a maximum weight,limit.
Each boat carries, at most, two people at the same time.
This is provided that the sum of the weight of those people is under or equal to the weight limit.

You need to return the minimum number of boats to carry every person in the array.
Constraints:
  1 <=people.length<=5*10^3
  1<=people{i}<=limit<=3*10^3

*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int RescueBoats(vector<int> people, int limit)
{
    int n=0;
    sort(people.begin(),people.end());
    int lowest=0;
    int highest=people.size()-1;
    while(!(highest<lowest)) {
        if(people[highest]+people[lowest]<=limit) {
          highest--;
          lowest++;
          n++;
        } else {
            highest--;
            n++;
        }

    }
    return n;
}

int main() {
    cout << RescueBoats({3,1,4,2,4},4)<<endl;
    cout << RescueBoats({1,1,1,1,2},3)<<endl;
    cout << RescueBoats({1,2},3)<<endl;
    cout << RescueBoats({5,5,5,5},5)<<endl;
    cout << RescueBoats({3,2,5,5},5)<<endl;
    return 0;
}