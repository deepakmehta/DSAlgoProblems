#include <iostream>
#include <string>

using namespace std;

bool IsInCorrectPosition(int currentQueen, int arr[]){
    if (currentQueen==0) return true;

    for (int i = currentQueen-1;i >=0;--i){
        if (arr[i]==arr[currentQueen]) return false;
        if (abs(arr[i]-arr[currentQueen])==(currentQueen-i)) return false;
    }
    return true;
}

void placeQueens(int n, int currentQueen, int arr[], int& result) {
    
    if (currentQueen==n) {
       // cout << "Combination found" << endl;
        result++;
        return;
    } 
    
    //cout << "Trying to set queen " << currentQueen << endl;

    for ( int i = 0 ; i < n;++i){
         arr[currentQueen]=i;
         // check the Queen is correctly placed or not
         if (IsInCorrectPosition(currentQueen,arr)) {
           // cout << "Queen looks okay at :" << i << endl;
             placeQueens(n, (currentQueen+1),arr,result);
         }
     }
}

int SolveNQueens(int n) {

	int result=0;
    int arr[n]={0};
    //while(arr[0]!=n){
        placeQueens(n,0,arr,result);
      //  arr[0]++;
    //}

    return result;
}

int main() {
    cout << SolveNQueens(4) << endl;
}