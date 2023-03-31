/*
In this challenge, you are given a list of words written in an alien language, where the words are sorted lexicographically by the rules of this language. Surprisingly, the aliens also use English lowercase letters, but possibly in a different order.

Given a list of words written in the alien language, you have to return a string of unique letters sorted in the lexicographical order of the alien language as derived from the list of words.

If there’s no solution, that is, no valid lexicographical ordering, you can return an empty string.

Constraints:
1<=words.length<=100
1<=words[i].length<=20
All characters in english lowercase
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

string FindDictionary(vector<string> words)
{
    string dict = "";
    map<int, int> charToFreqMap;
    map<int, set<int>> charToCharCorresp;
    for (auto y : words)
    {
        for (auto x : y)
        {
                charToFreqMap[x - 'a'] = 0;
        }
    }

    if (words.size() < 1)
        return "";
    // Iterate over the word;
    for (int i = 0; i < words.size() - 1; ++i)
    {
        string m1 = words[i];
        string m2 = words[i + 1];
        if (m1.size() > m2.size() && m1.find(m2) == 0)
        {
            return "";
        }

        for (int j = 0; j < min(m1.length(), m2.length()); ++j)
        {
            if (m1[j] != m2[j])
            {
                if (charToCharCorresp.find(m1[j] - 'a') != charToCharCorresp.end())
                {
                    if (charToCharCorresp[m1[j] - 'a'].find(m2[j] - 'a') == charToCharCorresp[m1[j] - 'a'].end())
                    {
                        charToCharCorresp[m1[j] - 'a'].insert(m2[j] - 'a');
                        charToFreqMap[m2[j] - 'a']++;
                    }
                }
                else
                {
                    charToCharCorresp.insert(pair<int, set<int>>(m1[j] - 'a', set<int>{m2[j] - 'a'}));
                    charToFreqMap[m2[j] - 'a']++;
                }
                break;
            }
        }
    }

    queue<int> root;
    for (auto y : charToFreqMap)
    {
        if (y.second == 0)
            root.push(y.first);
    }

    while (!root.empty())
    {
        int x = root.front();
        root.pop();
        dict += char(x + 'a');
        set<int> a = charToCharCorresp[x];
        for (auto z : a)
        {
            charToFreqMap[z]--;
            if (charToFreqMap[z] == 0)
            {
                root.push(z);
            }
        }
    }

    if (dict.size() != charToFreqMap.size())
        return "";
    return dict;
}

int main(int argc, char const *argv[])
{
//    cout << FindDictionary({"xro", "xma", "per", "prt", "oxh", "olv"}) << endl;
//    cout << FindDictionary({"o","l","m","s"}) << endl;
        cout << FindDictionary({"mdx","mars","avgd","dkae"}) << endl;
//       cout << FindDictionary({"mdxok","mrolw","mroqs","kptz","klr","klon","zvef","zrsu","zzs","orm","oqt"}) << endl;
//       cout << FindDictionary({"m","mx","mxe","mxer","mxerl","mxerlo","mxerlos","mxerlost","mxerlostr","mxerlostrpq","mxerlostrp"}) << endl;
    return 0;
}
