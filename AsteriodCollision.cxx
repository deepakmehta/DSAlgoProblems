/*
You’re given an array of integers, asteroids, representing a number of asteroids in a row.
For each asteroid, the absolute value represents its size,
and the sign represents its direction (positive meaning right, negative meaning left).
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions.
If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode.
Two asteroids moving in the same direction will never meet.

Constraints:

* 2≤ asteroids.length ≤10^4
* −1000≤ asteroids[i] ≤1000
* asteroids[i] !=0

*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> AsteroidCollisions(vector<int> asteroids)
{
    
    // newscenario.push_back(asteroids[0]);
    bool changed = true;
    while (changed){
        vector<int> newscenario;
        changed=false;
        for (int i = 0; i < asteroids.size(); ++i){
            if (newscenario.empty()) {
                newscenario.push_back(asteroids[i]);
            } else {
                int first = newscenario.back();
                int second = asteroids[i];
                if ((first>=0 && second>=0) || (first<0 && second<0)){
                    // same direction
                    newscenario.push_back(second);
                }else {
                    if (first<0) {
newscenario.push_back(second);
                    } else {
                    if (abs(first) == abs(second)) {
                        newscenario.erase(newscenario.end() - 1);
                    } else if (abs(first) > abs(second)){
                        //newscenario.push_back(first);
                        changed = true;
                    } else{
                        newscenario.erase(newscenario.end() - 1);
                        newscenario.push_back(second);
                        changed = true;
                    }
                    }
                }
            }
        }
        asteroids = newscenario;
    }
    return asteroids;
}

int main()
{
    vector<int> result;
    result = AsteroidCollisions({1, 2, 3, 4, 5, 6});
    for (auto x : result)
    {
        cout << x << " ," << endl;
    }
    cout << endl;
    result = AsteroidCollisions({-2, -3, -4, -6});
    for (auto x : result)
    {
        cout << x << " ," << endl;
    }
    cout << endl;
    result = AsteroidCollisions({1, 2, 5, -4});
    for (auto x : result)
    {
        cout << x << " ," << endl;
    }
    cout << endl;
    result = AsteroidCollisions({-1, 2, 2, -3});
    return 0;
}