
/*
Given two strings, check whether two strings are isomorphic to each other or not.
Two strings are isomorphic if a fixed mapping exists from the characters of one string to the characters of the other string.
For example, if there are two instances of the character "a"  in the first string,
both these instances should be converted to another character
(which could also remain the same character if "a" is mapped to itself) in the second string.
This converted character should remain the same in both positions of the second string
since there is a fixed mapping from the character "a" in the first string to the converted character in the second string.

Note: Two different characters cannot map to the same character.
      Furthermore, all the instances of a character must be replaced with another character while protecting the order of characters.
*/


#include <iostream>
#include <string>
#include <map>
using namespace std;

bool IsIsomorphic(std::string string1, std::string string2)
{
    map<char,char> s1tos2mapping;
    map<char,char> s2tos1mapping;
    if(string1.length()!=string2.length()) return false;

    for (int i =0; i<string1.length();++i){
        char s1 = string1[i];
        char s2 = string2[i];
       if (s1tos2mapping.find(s1)!=s1tos2mapping.end()){
        if (s1tos2mapping[s1] !=s2) return false;
       } else {
        s1tos2mapping[s1]=s2;
       }

if (s2tos1mapping.find(s2)!=s2tos1mapping.end()){
        if (s2tos1mapping[s2] !=s1) return false;
       } else {
        s2tos1mapping[s2]=s1;
       }

    }

    return true;
}

int main(){
    cout << IsIsomorphic("egg","axl") << endl;
    return 0;
}