/*
Given two strings, str1 and str2, find the index of the extra character that is present in only one of the strings.
0<=strings.length<=100
Either str2 =str1.length+1 or str1.length =str2.length+1
The string consists of lowercase english letters
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ExtraCharacterIndex(string firstString, string secondString)
{
    int extra=0;
    for(int i=0; i <firstString.length();++i) {
        extra^=(firstString[i]-'a');
    }
    for(int i=0; i <secondString.length();++i) {
        extra^=(secondString[i]-'a');
    }
    string& max=firstString;
    if (secondString.length()>firstString.length()) {
        max=secondString;
    }
    for(int i=0; i <max.length();++i) {
        if (extra==(max[i]-'a'))
        return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cout << ExtraCharacterIndex("wxyz","zwxgy") << endl;
    return 0;
}
