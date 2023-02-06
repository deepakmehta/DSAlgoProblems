#include <vector>
#include <iostream>
using namespace std;


int FindMissingNumber(vector<int> nums)
{
    for(int i = 0 ; i <nums.size();) {
      if (nums[i]!=0) {
         if (i+1 !=nums[i]) {

          int temp = nums[nums[i]-1];
          nums[nums[i]-1] =nums[i]; 
          nums[i]=temp;
          continue;
         }
      }
      ++i;
    }

    for(int i = 0 ; i <nums.size();++i) {
        if (nums[i]==0) return i+1;
    }

    return -1;
}

int main () {
    vector <int> nums{1,4,5,6,8,2,0,7};
    cout << FindMissingNumber(nums) << endl;
    return 0;
}