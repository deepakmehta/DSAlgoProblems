/*
Implement a data structure that can perform the following operations:
* Insert(): This function takes an integer as its parameter and, if it does not already exist in the set, adds it to the set, returning TRUE.
            If the integer already exists in the set, the function returns FALSE.
* Delete(): This function takes an integer as its parameter and, if it exists in the set, removes it, returning TRUE.
            If the integer does not exist in the set, the function returns FALSE.
* GetRandom(): This function takes no parameters. It returns an integer chosen at random from the set.

Note: Your implementation should aim to have a running time of O(1) (on average) for each operation.

*/

#include<vector>
#include<map>
#include<iostream>
#include<cstdlib>
using namespace std;

class RandomSet{
    vector<int> memory;
    map<int,int> keyTomemLocationMap;

public:
    RandomSet() {
    }

    /** Inserts a value to the dataset. Returns true if the dataset did not already contain the specified value. */
    bool insert(int prod) {
        if (keyTomemLocationMap.find(prod)!=keyTomemLocationMap.end()){
            return false;
        } else {
            memory.push_back(prod);
            keyTomemLocationMap.insert(pair<int,int>(prod,memory.size()-1));
            return true;
        }
        
    }

    /** Removes a value from the dataset. Returns true if the dataset contained the specified value. */
    bool remove(int prod) {

        if (keyTomemLocationMap.find(prod)!=keyTomemLocationMap.end()){
            int currloc=keyTomemLocationMap[prod];
            int endelement=memory.back();
            memory[currloc]=endelement;
            keyTomemLocationMap[endelement]=currloc;
            return true;
        } else {
            return false;
        }
    }

    /** Get a random value from the dataset. */
    int getRandomData() {
               
        return memory.size()==1?memory[0]: memory[rand()%(memory.size()-1)];
    }
};

int main(int argc, char const *argv[])
{
    RandomSet rs;
    rs.insert(25);
    cout << rs.getRandomData()<< endl;
    return 0;
}
