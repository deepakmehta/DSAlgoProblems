/*
Given a string, "palString", consisting of lowercase or uppercase letters,
return the length of the longest palindrome that can be built with those letters.
Note: Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
Constraints:
* 1≤  palString.length ≤2000
* palString consists of lowercase or uppercase English letters only.
*/

#include <string>
#include <iostream>
#include <map>
using namespace std;

int LongestPalindrome(string palString)
{
    map<char, int> freq;
    for (auto x : palString)
    {
        if (freq.find(x) == freq.end())
        {
            freq[x] = 1;
        }
        else
        {
            freq[x] += 1;
        }
    }

    bool oddconsidered = false;
    int result = 0;
    for (auto y : freq)
    {
       // cout << "pair: " << y.first << " : " << y.second << endl;
        if (!(y.second % 2))
        {
            result += y.second;
        }
        else if (!oddconsidered)
        {
            oddconsidered = true;
            result += y.second;
        }
        else
        {
            result += (y.second - 1);
        }
    }
    return result;
}

int main()
{
    cout << LongestPalindrome("aagshsgh") << endl;
    cout << LongestPalindrome("sfbaisdugfiubasdjFSDIBJS") << endl;
    cout << LongestPalindrome("dfssdnojfnaosbdf") << endl;
    cout << LongestPalindrome("GOODMORNINGTOYOU") << endl;
}
