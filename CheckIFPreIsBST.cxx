/*
Given an array of numbers,
return true if given array can represent preorder traversal of a Binary Search Tree,
else return false.
Expected time complexity is O(n).

Examples:

Input:  pre[] = {2, 4, 3}
Output: true
Given array can represent preorder traversal
of below tree
    2
     \
      4
     /
    3

Input:  pre[] = {2, 4, 1}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.

Input:  pre[] = {40, 30, 35, 80, 100}
Output: true
Given array can represent preorder traversal
of below tree
     40
   /   \
 30    80 
  \      \
  35     100 


Input:  pre[] = {40, 30, 35, 20, 80, 100}
Output: false
Given array cannot represent preorder traversal
of a Binary Search Tree.
*/

#include <vector>
#include <iostream>
using namespace std;

class CheckIfPreBST {

public:
bool Solve(vector<int>& x) {
 
}

};

int main() {
  CheckIfPreBST Solver;
  vector<int> arr{40, 30, 35, 80, 100};
  cout << Solver.Solve(arr) << endl;

  vector<int> arr2{40, 30, 35, 20, 80, 100};
  cout << Solver.Solve(arr2) << endl;

  return 0;
}