//https://www.geeksforgeeks.org/maximize-arrj-arri-arrl-arrk-such-that-i-j-k-l/
/* Maximize arr[j] – arr[i] + arr[l] – arr[k], such that i < j < k < l. Find the maximum value of arr[j] – arr[i] + arr[l] – arr[k], such that i < j < k < l 
Example: 
Let us say our array is {4, 8, 9, 2, 20}
Then the maximum such value is 23 (9 - 4 + 20 - 2)*/
#include<limits>
#include<iostream>
#include <algorithm>
using namespace std;

int maxDiff(int arr[], const int size){

if ( size <4) return -1;

// we will create four tables
// table 1 keep tracks of max a[l] at any given index
int table1[6] = {numeric_limits<int>::min};

for ( int i = size-1 ; i >=0;--i){
  table1[i] = max(table1[i+1],arr[i]);
}

// table 2 keep tracks of a[l]-a[k]
int table2[6] = {numeric_limits<int>::min};

for ( int i = size-2 ; i >=0;--i){

  table2[i] = max(table1[i]-arr[i],table2[i+1]);
}

// table3 keep tracks of max a[l]-a[k]+a[j]
int table3[5] = {numeric_limits<int>::min};

for ( int i = size-3 ; i >=0;--i){

  table3[i] = max(table2[i]+arr[i],table3[i+1]);
}

//table 4 keep tracks of max a[l] -a[k]+a[j]-a[i]
int table4[5] = {numeric_limits<int>::min};

for ( int i = size-4 ; i >=0;--i){

  table4[i] = max(table3[i]-arr[i],table4[i+1]);
}

return table4[0];

}


int main() {
    int arr[] = {4,8,9,2,20};
    cout << maxDiff(arr,5);
}