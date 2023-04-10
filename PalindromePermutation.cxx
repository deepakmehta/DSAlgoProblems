/*
For a given string, find whether or not a permutation of this string is a palindrome.
You should return TRUE if such a permutation is possible and FALSE if it isn’t possible.
    Constraints:
     1<=string.length<=1000
     The string consists of lowercase element

*/

#include <string>
#include <iostream>
#include<vector>
using namespace std;

bool PermutePalindrome(string str)
{

    vector<int> freq(26, 0);
    for (auto x : str)
    {
        freq[x - 'a']++;
    }
    int num_odds = 0;
    // number of odd digits
    for (auto x : freq)
    {
        
        if (x % 2)
        {
            num_odds++;
        }
    }
    return (num_odds > 1) ? false : true;
}

int main(int argc, char const *argv[])
{
    cout << PermutePalindrome("peas") << endl;
    cout << PermutePalindrome("abab") << endl;
    cout << PermutePalindrome("racecar") << endl;
    cout << PermutePalindrome("code") << endl;
    // cout << PermutePalindrome("peas") << endl;

    
    return 0;
}
