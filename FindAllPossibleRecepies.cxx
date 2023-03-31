/*
A list of recipes a chef can prepare from the supplied items is given. Ingredients required to prepare a recipe are mentioned in the ingredients list. The 
ith recipe has the name , and you can create it if you have all the needed ingredients from the ingredients ith list.
A recipe may be listed as an ingredient in a different recipe.
For example, the input may specify that custard is an ingredient in a trifle recipe
or that trifle is an ingredient in a custard recipe.

Identify which recipes a chef can prepare from the given ingredients from the supplies list.

*/
#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<queue>
using namespace std;

vector<string> FindAllRecipes( vector<string> recipes,
                               vector<vector<string>> ingredients,
                               vector<string> supplies) 
{
    vector<string> answer;
    map<string,int> elementToFreqMap;
    map<string,vector<string>> elementToRecipeMap;
    for(auto y: recipes){
        elementToFreqMap.insert(pair<string,int>(y,0));
    }
    /*
    for(auto x: ingredients){
        for(auto y: recipes){
        elementToFreqMap.insert(pair<string,int>(y,0));
    }
    }*/

    for(int i=0; i<recipes.size();++i){
        for(int j=0; j<ingredients[i].size();++j) {
            elementToRecipeMap[ingredients[i][j]].push_back(recipes[i]);
            elementToFreqMap[recipes[i]]++;
        }
    }
    
    queue<string> init;
    for(auto y:supplies){
        init.push(y);
    }

    while(!init.empty()){
        string temp =init.front();init.pop();
        vector<string> recepies = elementToRecipeMap[temp];
        for(auto r:recepies){
            elementToFreqMap[r]--;
            if(elementToFreqMap[r]==0){
                 answer.push_back(r);
                 init.push(r);
            }
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string>x;
    x=FindAllRecipes({"bread","sandwich","burger"},{{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}},{"yeast","flour","meat"});
    for(auto y : x) {
        cout<< y << ",";
    }
    cout << endl;
    x=FindAllRecipes({"bread","sandwich"},{{"yeast","flour"},{"bread","meat"}},{"yeast","flour","meat"});
    for(auto y : x) {
        cout<< y << ",";
    }
    cout << endl;
    x=FindAllRecipes({"bread"},{{"yeast","flour"}},{"yeast","flour","corn"});
    for(auto y : x) {
        cout<< y << ",";
    }
    cout << endl;
    x=FindAllRecipes({"pasta","egg","chicken"},{{"yeast","flour"},{"pasta","meat"},{"egg","meat","pasta"}},{"yeast","flour","meat"});
    for(auto y : x) {
        cout<< y << ",";
    }
    cout << endl;
    x=FindAllRecipes({"custard","trifle"},{{"yeast","flour","trifle","bananas","eggs","milk"},{"eggs","milk","custard"}},{"eggs","milk","yeast","flour","corn","bananas"});
    for(auto y : x) {
        cout<< y << ",";
    }
    cout << endl;
    return 0;
}
