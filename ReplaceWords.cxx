/*
You’re given a sentence consisting of words and a dictionary of root words.
Your task is to find all the words in the sentence whose prefix matches with a root word present in the dictionary,
and then to replace each matching word with the root word.

If a word in a sentence matches more than one root word in the dictionary,
replace it with the shortest matching root word,
and if the word doesn’t match any root word in the dictionary,
leave the word unchanged. Return the modified sentence as the output.
*/
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<istream>
#include<sstream>
using namespace std;

class TrieNode {
    public:
    bool isword=false;
    bool isroot=false;
    TrieNode* arr[26]={0};
    string W="";
    void AddWord(string& str, size_t loc) {
        if (loc>str.size()) return ;
        if(loc==str.size()) {
                 isword=true;
                 W=str;
                 return;
            }

        TrieNode* child=nullptr;
        child= arr[str[loc]-'a'];
        if (!child){
            arr[str[loc]-'a']=new TrieNode();
            arr[str[loc]-'a']->AddWord(str,loc+1);
                
        } else {
            child->AddWord(str,loc+1);
        } 
    }

    bool isWord(){
        return isword;
    }

string word(){
    return W;
}
    string GetPrefix(string& str, size_t loc){
        //bool reached_end=false;
        if(loc>=str.size()){
            return str;
        }
        TrieNode* child= arr[str[loc]-'a'];
        if (!child){
            if(isroot)return str;
            queue<TrieNode*> q;

            for(int i=0; i<26;++i){
                if(arr[i]) q.push(arr[i]);
            }
            while(!q.empty()) {
                TrieNode* child = q.front();
                q.pop();

                if(child->isWord()) return child->word();
                 for(int i=0; i<26;++i){
                if(child->arr[i]) q.push(child->arr[i]);
            }  
            }
          return str;
        }else {
            if (child->isWord()) {
                return  child->word();
            } else {
                return child->GetPrefix(str, loc+1);
            }
        }
        return str;
    }
};

class Trie {
   TrieNode root;
public:
   Trie(){
    root.isroot=true;
   }
   void Addword(string& str){
      root.AddWord(str,0);
   }
   string GetPrefix(string& str){
      return root.GetPrefix(str,0);
   }
};

string ReplaceWords(string sentence, vector <string> dictionary) 
{
    Trie t;
    for(auto x: dictionary){
        t.Addword(x);
    }

    istringstream ss(sentence);
        string part;
        string ans;
        while(getline(ss, part, ' ')){
            ans += t.GetPrefix(part);
            ans += " ";
        }
        ans.erase(ans.end()-1);
        return ans;
}

int main(int argc, char const *argv[])
{
    cout << ReplaceWords("where there is a will there is a way",{"wi","wa","w"})<<endl;
    cout << ReplaceWords("the quick brown fox jumps over the lazy dog",{"qui","f","la","d"})<<endl;
    cout << ReplaceWords("oops there is no matching word in this sentence",{"oops","there","is","no","matching","word","in","this","sentence"})<<endl;
    return 0;
}
