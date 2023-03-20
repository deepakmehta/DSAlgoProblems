#include<map>
#include<iostream>
using namespace std;

class TrieNode {
   public:
       std::map<char, TrieNode*> children;
       bool isWord;
 
       TrieNode(){
           this->isWord = false;
       }
};


class Trie {
     TrieNode* root;
     public:
          Trie(){
               this->root = new TrieNode();
          }
        
          // inserting string in trie
          void Insert( std::string word){
               TrieNode* node = this->root; 
               for (auto c:  word){
                    if (node->children.find(c) == node->children.end()){
                         node->children[c] = new TrieNode(); 
                    }
                    node = node->children[c];
               }
               node->isWord = true;
          }
          
          // searching for a string
          bool Search( std::string word){
               TrieNode* node = this->root;
               for (auto c:  word){
                    if (node->children.find(c) == node->children.end()){
                         return false;
                    }
                    node = node->children[c];
               }
               return node->isWord; 
          }

          // searching for a prefix
          bool SearchPrefix( std::string prefix){
               TrieNode* node = this->root;
               for (auto c:  prefix){
                    if (node->children.find(c) == node->children.end()){
                         return false;
                    }
                    node = node->children[c]; 
               }
               return true;
          }
};

int main(int argc, char const *argv[])
{
    Trie t;
    t.Insert("abc");
    t.Insert("def");
    t.Insert("abcd");
    cout<<t.Search("x") <<endl;
    cout<<t.SearchPrefix("ab") <<endl;
    return 0;
}
