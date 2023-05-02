/*
A “word square” is an ordered sequence of K different words of length K that,
when written one word per line, reads the same horizontally and vertically.
For example:
BALL
AREA
LEAD
LADY
    
 First, design a way to return true if a given sequence of words is a word square.

Second, given an arbitrary list of words, return all the possible word squares it contains. Reordering is allowed.

For example, the input list
[AREA, BALL, DEAR, LADY, LEAD, YARD]
should output

[(BALL, AREA, LEAD, LADY), (LADY, AREA, DEAR, YARD)]

Finishing the first task should help you accomplish the second task.

*/


#include <string>
#include <unordered_map>
#include <vector>
using Words = std::vector<std::string>;
class WordSquaresFinder {
 public:
  std::vector<Words> GetWordSquares(const Words& words) {
    all_words_ = words;
    CreatePrefixLookup();
    CollectWordSquares(/*partial_solution=*/Words());
    return std::move(result_);
  }
 private:
  size_t word_length() const { return all_words_[0].length(); }
  void CreatePrefixLookup() {
    for (const std::string& word : all_words_) {
      for (size_t length = 0; length < word.length(); length++) {
        std::string prefix = word.substr(0, length);
        AddToPrefixLookup(prefix, word);
      }
    }
  }
  void AddToPrefixLookup(const std::string& prefix, const std::string& word) {
    if (prefix_lookup_.find(prefix) == prefix_lookup_.end())
      prefix_lookup_[prefix] = std::vector<std::string>();
    prefix_lookup_[prefix].push_back(word);
  }
  void CollectWordSquares(const Words& partial_solution) {
    if (partial_solution.size() == word_length()) {
      // The partial solution is complete
      result_.push_back(partial_solution);
      return;
    }
    std::vector<std::string> candidate_words =
        FindAllCandidates(partial_solution);
    for (const std::string& word : candidate_words) {
      // Recurse
      Words new_partial_solution = partial_solution;
      new_partial_solution.push_back(word);
      CollectWordSquares(new_partial_solution);
      // Keep looking for other solutions
    }
    // When we come here we've checked all words, and all possible solitions
    // have been stored. Time to start backtracking.
  }
  std::vector<std::string> FindAllCandidates(const Words& partial_solution) {
    int num_words = partial_solution.size();
    std::string prefix = GetNthLetters(partial_solution, num_words);
    return prefix_lookup_[prefix];
  }
  std::string GetNthLetters(const Words& words, int n) {
    std::string result;
    for (const std::string& word : words)
      result += std::string{word[n]};
    return result;
  }
  Words all_words_;
  std::unordered_map<std::string, std::vector<std::string>> prefix_lookup_;
  std::vector<Words> result_;
};