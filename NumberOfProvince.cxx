#include<vector>
#include <iostream>
using namespace std;


void dump(vector<vector<int>>& iscityConnected) {
    cout << "{ ";
    for(int i = 0 ; i <iscityConnected.size();++i) {
        for ( int j=0; j<iscityConnected[0].size();++j) 
        {
            cout << iscityConnected[i][j] << " ," ;
        }
        cout << " }";
    }
    cout << " }" << endl;
}

void Traverse(vector<vector<int>>& isCityConnected, int i , int j) {
    isCityConnected[i][j]=0;
    isCityConnected[j][i]=0;
    for ( int k=0; k<isCityConnected[0].size();++k) {
            if (isCityConnected[j][k]==1) {
                //numberofProvince++;
                Traverse(isCityConnected,j, k);
            }
    }
}

int FindConnectedCities(vector<vector<int>> isCityConnected)
{
    int numberofProvince=0;
    for(int i = 0 ; i <isCityConnected.size();++i) {
        for ( int j=i; j<isCityConnected[0].size();++j) {
            if (isCityConnected[i][j]==1) {
                numberofProvince++;
                Traverse(isCityConnected,i,j);
            }
        }
    }
    return numberofProvince;
}

int main() {
    vector<vector<int>> isCityConnected {{1,1,0},{1,1,0},{0,0,1}};
    cout << FindConnectedCities(isCityConnected) << endl;
}