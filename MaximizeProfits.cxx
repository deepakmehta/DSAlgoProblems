/*
You need to develop a program for making automatic investment decisions for a busy investor.
The investor has some start-up capital, c , to invest and a portfolio of projects in which they would like to invest in.
The investor wants to maximize their cumulative capital as a result of this investment.
To help them with their decision, they have information on the capital requirement for each project and the profit it’s expected to yield.
For example, if project A has a capital requirement of 3, and the investor’s current capital is 1, then the investor can’t invest in this project.
On the other hand, if the capital requirement of a project B is 1, then the investor can invest in this project.
Now, supposing that the project yields a profit of 2, the investor’s capital at the end of the project will be 1 + 2 = 3.
The investor can now choose to invest in project A as well since their current capital has increased.

As a basic risk-mitigation measure, the investor would like to set a limit on the number of projects,k, they invest in.
For example, if the value of k is 2, then we need to identify the two projects that the investor can afford to invest in,
given their capital requirements, and that yield the maximum profits.

Further, these are one-time investment opportunities, that is, the investor can only invest once in a given project.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int MaximumCapital(int c, int k, vector<int> capitals, vector<int> profits)
{
    priority_queue< pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> maxheap;
    priority_queue< pair<int,int>,vector< pair<int,int>>,greater<pair<int,int>>> minheap;
    

    // lets collect all the capitals in the min order
    for(int i=0;i<capitals.size();++i){
         minheap.push( pair<int,int>(capitals[i],i));
    }

    int capital=c;
    while(k-->0) {
    while( minheap.top().first<=c) {
        maxheap.push(pair<int,int>( profits[minheap.top().second],minheap.top().second));
        minheap.pop();
    }

    if(maxheap.empty()) break;     
      //lets get the max profit element
      pair<int,int> trade=maxheap.top();
      maxheap.pop();
      capital+=trade.first;

    }
    

     return capital;
}

int main(){

cout<<MaximumCapital(1 , 2 , {1,2,2,3} , {2,4,6,8})<<endl;
cout<<MaximumCapital(2 , 2 , {1,2,3,4} , {1,3,5,7})<<endl;
cout<<MaximumCapital(2 , 3 , {1,3,4,5,6} , {1,2,3,4,5})<<endl;
cout<<MaximumCapital(0 , 3 , {0,1,2} , {1,2,3})<<endl;
cout<<MaximumCapital(1 , 3 , {1,2,3,11,19,21} , {2,7,9,16,17,18})<<endl;
cout<<MaximumCapital(0 , 1 , {1,1,2} , {1,2,3})<<endl;

}