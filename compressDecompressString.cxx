/*
In this exercise, you're going to decompress a compressed string.

Your input is a compressed string of the format number[string] and the decompressed output form should be the string written number times. For example:

The input

3[abc]4[ab]c

Would be output as

abcabcabcababababc

Other rules
Number can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa

One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab

Characters allowed as input include digits, small English letters and brackets [ ].

Digits are only to represent amount of repetitions.

Letters are just letters.

Brackets are only part of syntax of writing repeated substring.

Input is always valid, so no need to check its validity.
*/

#include<string>
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;


string decompress(string encoded){
    
    string decoded="";
    stack<string> bracketString;
    stack<int> numbers;
 
 bracketString.push("");
    int brackets=0;
    int number=0;
    for(int i=0; i<encoded.size();++i){
        if(encoded[i]=='['){
          numbers.push(number);
          number=0;
          bracketString.push("");
          brackets++;
        } else if (encoded[i]==']'){
            brackets--;
            if (brackets==-1){
                assert(0&&"Malformed string");
                // lets evaluate
            }
            string torepeat=bracketString.top();
            bracketString.pop();
            int num=numbers.top();
            numbers.pop();
            string expanded("");
            for(int i=0; i<num;++i){
               expanded+=torepeat;
            }
            bracketString.top().append(expanded);
        }
        else if(encoded[i]>='0' && encoded[i]<='9'){
            number=number*10+ encoded[i]-'0';
        } else {
            if(bracketString.empty()){
                assert(0&& "malformed string");
            }
           bracketString.top().append(1,encoded[i]); 
        }

    }
    return bracketString.top();
}

int main(int argc, char const *argv[])
{
    cout << decompress("2[a]3[bcd]2[3[a]b]") << endl;
    return 0;
}
