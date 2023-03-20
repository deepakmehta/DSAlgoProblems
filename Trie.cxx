/*
Trie is a tree-like data structure used to store strings.
The tries are also called prefix trees because they provide very efficient prefix matching operations.
Implement a trie data structure with three functions that perform the following tasks:

Insert a string.
Search a string.
Search for a given prefix in a string.
Constraints
 1<=words.length,prefix.length<=200
 String consists only of lowercase letters
 Atmost 3*10^3 calls will be made to functions

*/

#include<iostream>
using namespace std;

class MyTrieNode {
    public:
    bool isWord=false;
    MyTrieNode* array[26]={0};
    MyTrieNode(bool word):isWord(word){ }
    ~MyTrieNode() {
        for(auto x: array) {
            delete x;
        }
    }
};

class Trie {
    MyTrieNode* start_;
     void Insert(const string&word, int loc ,MyTrieNode* curr) {
        if (loc==word.size()) {
            curr->isWord=true;
            return;
        }
        char x = word[loc];
        if(curr->array[x-'a']!=nullptr) {
            Insert(word,loc+1,curr->array[x-'a']);
        } else {
        MyTrieNode* newNode=nullptr;
        if (loc==word.size()-1) {
          newNode=new MyTrieNode(true);
        } else {
            newNode=new MyTrieNode(false);
        }
        curr->array[x-'a']=newNode;
    Insert(word,loc+1,newNode);
        }
     }

bool Search(const string&word, int loc ,MyTrieNode* curr) {
        if (loc==word.size()) return curr->isWord;
        char x = word[loc];
        if(curr->array[x-'a'] !=nullptr) {
            return Search(word,loc+1,curr->array[x-'a']);
        } else {
            return false;
        }
       return false;        
     }

     bool SearchPrefix(const string&word, int loc ,MyTrieNode* curr) {
        if (loc==word.size()) return true;
        char x = word[loc];
        if(curr->array[x-'a'] !=nullptr) {
            return SearchPrefix(word,loc+1,curr->array[x-'a']);
        } else {
            return false;
        }
        return false;
     }

    public:
        Trie():start_(new MyTrieNode(false)){
            // constructor
        }

        // inserting string in trie
        void Insert(string word){
            Insert(word,0,start_);
        }

        // searching for a string
        bool Search(string word){
            
            return Search(word,0,start_);
        }

        // searching for a prefix
        bool SearchPrefix(string prefix){
            
            return SearchPrefix(prefix,0,start_);
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
