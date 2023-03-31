/*
Given a string containing an arithmetic expression, implement a basic calculator that evaluates the expression string.
The expression string can contain integer numeric values and should be able to handle the “+” and “-” operators, as well as “()” parentheses.

*/

#include<string>
#include<stack>
#include<iostream>
using namespace std;

int Calculator(string expression) {
    
    stack<string> s;
    
    string temp="";
    int number=0;
    for(auto x: expression) {
        if(x==' ') {

        }else if (x=='(') {
            if(temp!="") {
                s.push(temp);
                temp="";
            }
            s.push("(");
        } else if (x=='+') {
            if(temp!="") {
                s.push(temp);
                temp="";
            }
            s.push("+");
        } else if (x=='-') {
            if(temp!="") {
                s.push(temp);
                temp="";
            }
            s.push("-");
        } else if (x==')') {
            if(temp!="") {
                s.push(temp);
                temp="";
            }
            
            number=0;
            while(s.top()!="(") {
              string temp=s.top();
              s.pop();
              if(temp=="+") {
                //isplus=true;
                //s.pop();
                string t=s.top();
                s.pop();
                s.push(std::to_string(atoi(t.c_str())+number));
              } else if(temp=="-"){
                //isminus=true;
                string t=s.top();
                s.pop();
                s.push(std::to_string(atoi(t.c_str())+number));
              }
              else {
                number=atoi(temp.c_str());
              }
              
            }
            s.pop();
            s.push(std::to_string(number));
        } else {
           temp+=x;
        }
    }
    return number;
}


int main(int argc, char const *argv[])
{
    cout << Calculator("12 - (6 + 2) + 5") << endl;
    cout << Calculator("(8 + 100) + (13 - 8 - (2 + 1))") << endl;
    cout << Calculator("40 - 25 - 5") << endl;
    cout << Calculator("(27 + (7 + 5) - 3) + (6 + 10)") << endl;
    return 0;
}
