/*
Given two strings, a and b, return an array of all the start indexes of b's anagrams in a. We may return the answer in any order.

An anagram is a word or phrase created by rearranging the letters of another word or phrase
while utilizing each of the original letters exactly once.

Constraints:

1 ≤ a.length, b.length≥3×10^3

a and b consist of only lowercase letters
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> FindAnagrams(string a, string b)
{
    vector<int> result;
    if (b.length() > a.length())
        return {};
    // lets create freq map for b
    vector<int> bfreqMap(26, 0);
    for (auto x : b)
    {
        bfreqMap[x - 'a']++;
    }

    int s = 0;
    int e = 0;

    cout << " { ";
    for (auto y : bfreqMap)
    {
        cout << y << ",";
    }
    cout << " } " << endl;

    while (e < a.length())
    {

        bfreqMap[a[e] - 'a']--;
        if (bfreqMap[a[e] - 'a'] == -1)
        {
            // Negative found
            cout << " Negative case: " << " s: " << s << " e: " << e << endl;
            cout << " { ";
            for (auto y : bfreqMap)
            {
                cout << y << ",";
            }
            cout << " } " << endl;

            // lets move the start to e ;
            while  ((s < e) )
            {
                bfreqMap[a[s] - 'a']++;
                s++;
                //if ( (a[s]==a[e])) break; 
            }
            cout << "Making the freq map clean" << endl;
            cout << " { ";
            for (auto y : bfreqMap)
            {
                cout << y << ",";
            }
            cout << " } " << endl;
            cout << "s: " << s << endl;
        }
        else if (((e - s) + 1) == b.length())
        {
            cout << " String size match: " << " s: " << s << " e: " << e << endl;
            result.push_back(s);
            bfreqMap[a[s++] - 'a']++;
        }
        e++;

    }
    return result;
}

int main()
{
    vector<int> x;
    x = FindAnagrams("cbaebabacd", "abc");
    for (auto y : x)
    {
        cout << y << " ,";
    }
    cout << endl;
}