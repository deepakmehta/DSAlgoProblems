/*
Given an array of strings called products and a word to search,
design a system that, when each character of the searched word is typed,
suggests at most three product names from products.
Suggested products should share a common prefix with the searched word.
If more than three products exist with a common prefix,
return the three product names that appear first in lexicographical order.

Return the suggested products, which will be a list of lists after each character of searched word is typed.

Constraints:
 1<= products.length<=1000
 1<=products[i].length<=3000
 1<= sum(product[i].length)<= 2*10^3
 All strings of products are unique
 products[i] consists of lowercase letters
 1<=Searched  word.length<=1000
 The searched word consists of lowercase letters

*/

#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

class MyTrieNode {
  public:
   map < char, MyTrieNode * > children;
   bool isWord=false;
   vector <  string > searchWords;
};

class Trie {
     MyTrieNode* root;
     public:
          Trie(){
               this->root = new MyTrieNode();
          }
        
          // inserting string in trie
          void Insert( std::string word){
               MyTrieNode* node = this->root; 
               for (auto c:  word){
                    if (node->children.find(c) == node->children.end()){
                         node->children[c] = new MyTrieNode(); 
                    }
                    node = node->children[c];
               }
               node->isWord = true;
          }

          vector<string> SetSuggestions(MyTrieNode* node, string curr) {
            
            for(auto x: node->children) {
                string newcurr=curr;
                newcurr+=x.first;
                vector<string> r =SetSuggestions(x.second,newcurr);
                node->searchWords.insert(node->searchWords.end(),r.begin(),r.end());
            }
            vector<string> r;

            if(node->isWord) r.push_back(curr);
            r.insert(r.end(),node->searchWords.begin(),node->searchWords.end());
            return r;
          }

void SetSuggestions() {
    MyTrieNode* node = this->root;
    SetSuggestions(node,"");
}
          // searching for a string
          vector<vector<string>> Search( string word){
               vector<vector<string>> r;
               MyTrieNode* node = this->root;
               for (auto c:  word){
                    if (node->children.find(c) == node->children.end()){
                         break;
                    } 
                    node = node->children[c];
                    if (node->searchWords.size()>3) {
                        r.push_back(vector<string>(node->searchWords.begin(),node->searchWords.begin()+3));
                    } else {
                        r.push_back(vector<string>(node->searchWords));
                    }
               }
               return r; 
          }

};


vector<vector<string>> SuggestedProducts(vector<string> products, string searchWord){
  
  Trie t;
  for(auto x: products) {
    t.Insert(x);
  }

  t.SetSuggestions();
  return t.Search(searchWord);

}

int main() {
    vector<vector<string>> r;
    r=SuggestedProducts({"mobile","mouse","moneypot","monitor","mousepad"},"mouse");
    for( auto m: r) {
        for(auto n:m) {
            cout << n << ",";
        }
        cout << endl;
        }
        cout << endl;
    r=SuggestedProducts({"havana"},"havana");
    for( auto m: r) {
        for(auto n:m) {
            cout << n << ",";
        }
        cout << endl;
        }
        cout << endl;
    r=SuggestedProducts({"bags","baggage","banner","box","cloths"},"bags");
    for( auto m: r) {
        for(auto n:m) {
            cout << n << ",";
        }
        cout << endl;
        }
        cout << endl;
}
