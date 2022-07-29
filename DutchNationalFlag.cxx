/*
Given an array A[] consisting only 0s, 1s and 2s.
The task is to write a function that sorts the given array.
The functions should put all 0s first, then all 1s and all 2s in last.

This problem is also the same as the famous “Dutch National Flag problem”.
The problem was proposed by Edsger Dijkstra.
The problem is as follows:

Given N balls of colour red, white or blue arranged in a line in random order.
You have to arrange all the balls such that the balls with the same colours are adjacent with the order of the balls, with the order of the colours being red, white and blue
(i.e., all red coloured balls come first then the white coloured balls and then the blue coloured balls). 
*/

#include <vector>
#include<iostream>
using namespace std;

class DutchProblem {
 public:
   void Solve(vector<int>& arr) {

    int low = -1;
    int high = arr.size();
    int index = 0;
    while (index <high) {
       // lets access the element
       if ( arr[index] ==0) {
        // swap the numbers
        int temp = arr[low+1];
        arr[++low] = 0;
        arr[index] = temp;
        if ( low == index) index++;
       } else if ( arr[index]==1){
              index++;
       } else {
        // swap the numbers
        int temp = arr[high-1];
        arr[--high] = 2;
        arr[index] = temp;
       }
    }

   }


};



int main() {
   DutchProblem solver;
   vector<int> arr(20);

   for ( int i = 0 ; i < 20;++i) arr[i] = rand()%3;

   cout << "UnSorted Vector" << endl;
   for( auto x: arr) cout << x << " , ";
   cout << endl;
   solver.Solve( arr);
   cout << "Sorted Vector" << endl;
   for( auto x: arr) cout << x << " , ";
   cout << endl;
   return 0;   
}