/*
Given a string having digits from 2 – 9 inclusive,
return all the possible letter combinations that can be made from the numbers in the string.
Return the answer in any order.
A mapping of digits to letters is given below.
Note: 1 doesn’t map to any letter.

*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;



vector<string> LetterCombinations(string digits)
{
    const string mapping[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> r;
    if(digits.empty()) return r;

    for(const char x:mapping[int(digits[0]-'0')-1]){
        r.push_back(string(1,x));
    }
    
    for(int i=1; i<digits.length();++i) {
        vector<string>temp;
        for (const char x : mapping[int(digits[i] - '0') - 1])
        {
            for(auto y:r){
                temp.push_back(y+string(1,x));
            }
        }
        r=temp;
    }

    return r;
}

int main(int argc, char const *argv[])
{
    vector<string>r;
    r=LetterCombinations("2");
    for(auto x:r){
        cout<<x << ",";
    }
    cout << endl;
r=LetterCombinations("73");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
r=LetterCombinations("426");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
r=LetterCombinations("78");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
r=LetterCombinations("925");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
r=LetterCombinations("39");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
r=LetterCombinations("25");
for(auto x:r){
    cout<<x << ",";
}
cout << endl;
    return 0;
}

