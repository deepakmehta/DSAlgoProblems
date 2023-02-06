/*
For a given unsorted array, find the first k missing positive numbers in that array.
constraints:
  * Ignore all negative numbers
  * If missing numbers length != k, add missing numbers upto k
  * 1 <= k <=10^4
  * 1<=missingnumbers<=200
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> FirstKMissingNumbers(vector<int> missingNums, int k)
{
    vector<int>result(k,-1);
    
    for (int i =0; i< missingNums.size();++i) {
        if (missingNums[i]!=i+1) {
            if ( (missingNums[i] <=0)||
                 (missingNums[i]>missingNums.size()))
                 continue;
            int temp = missingNums[i];
            if (missingNums[temp-1]!=temp) {
                missingNums[i] = missingNums[temp-1];
                missingNums[temp-1] = temp;
                i--;
            }
        }
    }
    
    int last_num=0;
    int j=0;
    for (int i =0; i< missingNums.size();++i) {
        if (missingNums[i]!=i+1) {
            result[j++]=i+1;
            last_num=i+1;
        } else {
            last_num=missingNums[i];
        }
    }

//cout << "J: " << 
    for(;j<result.size();j++) {
        result[j]=++last_num;
    }
    return result;
}

void PrintResult(vector<int>& result) {
    for (auto x: result) {
        cout << x << " ," ;
    }
}

int main() {
    vector<int> result = FirstKMissingNumbers({1,-1,2},2);
    PrintResult(result); 
    cout << endl;
}