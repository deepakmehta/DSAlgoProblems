/*
There are n gas stations along a circular route, where the amount of gas at the station is gas{i}.
We have a car with an unlimited gas tank and it costs cost{i} of gas to travel from the ith station to its next (i+1)th station.
We begin the journey with an empty tank at one of the gas stations.

Given two integer arrays, gas and cost, return the starting gas station’s index if we can travel around the circuit
once in the clockwise direction. Otherwise, return −1.

If there exists a solution, it is guaranteed to be unique.
Constraints:
  gas.length==cost.length
  1<=gas.length<=10^3
  0<=gas{i}
  cost<=10^3

*/

#include <iostream>
#include <vector>
using namespace std;

int GasStationJourney(vector<int> gas, vector<int> cost)
{
   
    gas.insert(gas.end(),gas.begin(),gas.end());
    cost.insert(cost.end(),cost.begin(),cost.end());
    
    int s=-1;
    for(int i=0; i <gas.size()/2;++i) {
       if(gas[i]<cost[i]) {
        continue;
       }
       //cout << "Lets check: " << i << endl;
       // lets check if path exists
       int j=i;   
       int netgas=0;
       int netcost=0;
       while(j!=(i+gas.size()/2)) {
        netgas+=gas[j];
        netcost+=cost[j];
        
        if (netgas<netcost) {
          break;
        }
          j++;
       }
       if (j==(i+gas.size()/2)) {
        s=i;
        break;
       }

    }

    return s;
}

int main() {
    //cout <<GasStationJourney({1,2,3,4,5},{3,4,5,1,2})<<endl;
    cout <<GasStationJourney({2,3,4},{3,4,3})<<endl;
    //cout <<GasStationJourney({1,1,1,1,10},{2,2,1,3,1})<<endl;
    //cout <<GasStationJourney({1,1,1,1,1},{1,2,3,4,5})<<endl;
    //cout <<GasStationJourney({1},{1})<<endl;
}