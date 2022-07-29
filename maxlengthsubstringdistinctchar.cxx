/* Given a string, find the length of the longest substring, which has all distinct characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring with distinct characters is "abc". */



using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int start=0;
    int end=0;
    int chArray[26] = {0};
    while (end != str.length()-1) {
      // lets look at the character
       if ( chArray[str[end]-'a'] ==0) {
         chArray[str[end] - 'a']++;
         maxLength=max(maxLength, end++-start+1);
       } else {
         while ( true) {
           if (str[start] != str[end]) {
             start++;
           } else {
             start++;
             end++;
             break;
           }
         }
       }

    }
    // TODO: Write your code here
    return maxLength;
  }
};


int main() {
    std::cout << NoRepeatSubstring::findLength("aabccbb") << std::endl;
}
