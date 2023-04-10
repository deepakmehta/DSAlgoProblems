/*
Given a number n, calculate the corresponding Tribonacci number. The Tribonacci sequence Tn is defined as:
 T0=0 , T1=1, T2=1, Tn+3=Tn+Tn+1+Tn+2 for n>=0
 The input number n, is non negative

*/
#include<iostream>
using namespace std;

int FindTribonacci(int n)
{
    if(n==0) return 0;
    if(n==1||n==2) return 1;

    int t0=0;
    int t1=1;
    int t2=1;
    for(int i= 3; i<=n;++i){
        int x = t0+t1+t2;
        t0=t1;
        t1=t2;
        t2=x;
    }
    return t2;
}

int main(int argc, char const *argv[])
{
    cout << FindTribonacci(0)<<endl;
    cout << FindTribonacci(3)<<endl;
    cout << FindTribonacci(5)<<endl;
    return 0;
}
