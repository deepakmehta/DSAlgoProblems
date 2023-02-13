/*
Given an integer array, nums, of length n, where all the integers of nums are in the range [1,n]
and each integer appears once or twice, return an array of all the integers that appear twice.

Note: Make sure to write an algorithm that runs in O(n) time and uses only constant extra space.

Constraints:
 * n==nums.length
 * 1<=n<=10^5
 * 1<=nums[i]<=n
 * Each element in number appears once or twice

*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> FindDuplicates(vector<int> nums)
{
    // your code will replace this placeholder return statement
    vector<int>r;
    for(int i=0; i<nums.size();++i){
        if (nums[i]!=i+1){
            int temp=nums[i];
            if(nums[temp-1]!=temp){
                nums[i]=nums[temp-1];
                nums[temp-1]=temp;
                i--;
            }
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i]!=i+1) r.push_back(nums[i]);
    }
    return r;
}

int main()
{
    vector<int> r;
    r = FindDuplicates({4, 3, 2, 7, 8, 2, 3, 1});
    for (auto x : r)
    {
        cout << x << ",";
    }
    cout << endl;
    r = FindDuplicates({2, 3, 4, 7, 8, 6, 5, 10, 8, 6});
    for (auto x : r)
    {
        cout << x << ",";
    }
    cout << endl;
    r = FindDuplicates({23, 4, 5, 15, 6, 22, 21, 8, 9, 17, 23, 9, 20, 1, 16, 7, 2, 19, 8, 17, 4, 15, 1});
    for (auto x : r)
    {
        cout << x << ",";
    }
    cout << endl;
    r = FindDuplicates({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 15, 14, 16, 18});
    for (auto x : r)
    {
        cout << x << ",";
    }
    cout << endl;
    return 0;
}
