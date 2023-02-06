/*
Given a non-empty unsorted array taken from a range of 1 to n.
Due to some data error, one of the numbers is duplicated, which results in another number missing.
Create a function that returns the corrupt pair (missing, duplicated).
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int,int> FindCorruptPair(vector<int> nums)
{
    for( int i=0; i <nums.size();++i) {
        if (nums[i]!=i+1) {
            int temp = nums[i];
            if(nums[temp-1]!=temp) {
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
            i--;
            }
        }
    }

for( int i=0; i <nums.size();++i) {
    if (nums[i]!=i+1) {
        return pair<int,int>(i+1,nums[i]);
    }
}    

    return {-1, -1};
}

int main() {
    vector<int>nums{3,1,2,5,2};
    pair<int,int> r = FindCorruptPair(nums);
    cout << "{ " << r.first << ", " << r.second << "}" << endl;
}