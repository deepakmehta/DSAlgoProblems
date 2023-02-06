/*
There are a total of n classes labeled with the English alphabet ( A , B , C , and so on).
Some classes are dependent on other classes for compilation. For example, if class B  extends class A , then B has a dependency on A .
Therefore, A must be compiled before B.Given a list of the dependency pairs, find the order in which the classes should be compiled.

Constraints:
  * Class number should be a character
  * 0 <= Depdendencies.length <=5000
  * dependencies[i].length = 2
  * All dependencies pairs are unique
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


vector<char> FindCompilationOrder(vector<vector<char>> dependencies)
{
    vector<char> result;
  //map<char,int> CharToIntMap;
  map<int,int> inDegreeMap;
  queue<char> sources;
  vector<vector<int>> graph(26, vector<int>());
  int firstElement=0;
  for (auto x: dependencies) {
    int firstIndex = x[0]-'A';
    int secondIndex = x[1]-'A';
    if(inDegreeMap.find(firstIndex)==inDegreeMap.end()){
        inDegreeMap.insert(pair<int,int>(firstIndex,1));
    } else {
        inDegreeMap[firstIndex]+=1;
    }
  
    if(inDegreeMap.find(secondIndex)==inDegreeMap.end()){
        inDegreeMap.insert(pair<int,int>(secondIndex,0));
    } 
    graph[secondIndex].push_back(firstIndex);
  }

  // lets get all the sources
  for (auto x:inDegreeMap) {
    if (x.second==0) sources.push(x.first);
  }

  while(!sources.empty()) {
      int src = sources.front();
      result.push_back(char(src+'A'));
      sources.pop();

      for (auto y: graph[src]) {
           inDegreeMap[y]-=1;
           if (inDegreeMap[y]==0) sources.push(y);
      }
  }
  return result;
}

int main() {

  vector<vector<char>> dependencies{ {'B', 'A'}, { 'C', 'A' }, { 'D', 'C' }, { 'E', 'D' }, { 'E', 'B' } };

  vector<char> order = FindCompilationOrder(dependencies);
  for(auto x: order) cout << x << " , " ;
  cout << endl;  
}

