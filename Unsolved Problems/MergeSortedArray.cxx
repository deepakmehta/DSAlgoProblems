/*
Given two sorted integer arrays, nums1 and nums2
, and the number of data elements in each array, m and n
, implement a function that merges the second array into the first one. You have to modify nums1 in place.

Note: Assume that nums1 has a size equal to m+n, meaning it has enough space to hold additional elements from nums2.

Constraints:
nums1.length=m+n
nums2.length=n
0 <=m,m<=200
-10^3 <=nums1[i],nums2[i]<=10^3
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> mergeSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    while
    return nums1;
}

int main(int argc, char const *argv[])
{
    vector<int> result;
    result = mergeSortedArray({1, 2, 3, 0, 0, 0}, 3, {4, 5, 6}, 3);
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = mergeSortedArray({-1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0}, 5, {-1, -1, 0, 0, 1, 2}, 6);
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = mergeSortedArray({6, 7, 8, 9, 10, 0, 0, 0, 0, 0}, 5, {1, 2, 3, 4, 5}, 5);
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = mergeSortedArray({10, 49, 99, 110, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 5, {1, 2, 4, 7, 8, 12, 15, 19, 24, 50, 69, 80, 100}, 13);
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    result = mergeSortedArray({0, 1, 4, 9, 0, 0, 0, 0, 0, 0}, 4, {-111, -20, -5, 5, 11, 20}, 6);
    for (auto x : result)
    {
        cout << x << " ,";
    }
    cout << endl;
    return 0;
}
