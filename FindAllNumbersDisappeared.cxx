/* Given an array, nums, of n integers where nums[i] is in the range [1,n] ,
 return an array of all the integers in the range  [1,n]that doesn’t appear in nums.

Constraints:
 n=nums.length
 1<=n<=10^5
 1 <=nums[i]<=n
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> FindDisappearedNumbers(vector<int> nums)
{
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
        if(nums[i]!=i+1) r.push_back(i+1);
    }
    

    return r;
}

int main()
{
    vector<int> result;
    result = FindDisappearedNumbers({1, 2, 5, 2, 2});
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = FindDisappearedNumbers({3, 7, 3, 1, 9, 13, 10, 3, 8, 7, 1, 5, 13});
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = FindDisappearedNumbers({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = FindDisappearedNumbers({2, 6, 8, 3, 9, 18, 16, 11, 10, 2, 14, 17, 5, 3, 7, 17, 4, 5});
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    return 0;
}