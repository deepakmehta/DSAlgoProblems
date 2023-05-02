/*
Given a string S and a set of words D, find the longest word in D that is a subsequence of S.

Word W is a subsequence of S if some number of characters, possibly zero, can be deleted from S to form W, without reordering the remaining characters.

Note: D can appear in any format (list, hash table, prefix tree, etc.

For example, given the input of S = "abppplee" and D = {"able", "ale", "apple", "bale", "kangaroo"} the correct output would be "apple"

The words "able" and "ale" are both subsequences of S, but they are shorter than "apple".
The word "bale" is not a subsequence of S because even though S has all the right letters, they are not in the right order.
The word "kangaroo" is the longest word in D, but it isn't a subsequence of S.


*/


#include<iostream>
#include<vector>
using namespace std;

bool IsSubSequence(string&S,string&x){
    int i=0;
    int j=0;
    while (i<S.size() && j<x.size()){
         if (S[i]==x[j]){
             i++;
             j++;
         } else {
            i++;
         }
    }
    return j==x.size();
}

int FindLongestWord(string S, vector<string>D){
    int longestSubString=-1;
    for(auto x: D){
        if(longestSubString==-1 || longestSubString<x.size()){
            if (IsSubSequence(S,x)){
                longestSubString=x.size();
            }
        }
    }
    return longestSubString;
}

int main() {
    cout << FindLongestWord("abppplee",{"able","ale","apple","bale","kangroo"}) << endl;
}



std::string find_longest_word_in_string(const std::string& letters, const std::vector<std::string>& words) {
  // Corner Case: Either one of them is empty.
  if (letters.empty() || words.empty()) {
    return " ";
  }
  std::unordered_map<char, TupleSet> letter_positions;
  // Initialize the data structure. Filter out any empty words that may appear
  // in the words list.
  for (std::string w : words) {
    if (w.empty()) {
      continue;
    }
    letter_positions[w[0]].insert({w, 0});
  }
  std::string longest_word = "";
  for (char c : letters) {
    if (letter_positions.find(c) == letter_positions.end()) {
      continue;
    }
    auto curr_positions = letter_positions[c];
    for (auto pair : curr_positions) {
      std::string curr_word = pair.first;
      pair.second++;
      // Remove the pair from the set
      letter_positions[c].erase(pair);
      // We found a subsequence.
      if (curr_word.size() == pair.second) {
        if (curr_word.size() > longest_word.size()) {
          longest_word = curr_word;
        }
      } else {
        letter_positions[curr_word[pair.second]].insert(pair);
      }
    }
  }
  return longest_word;
}
    