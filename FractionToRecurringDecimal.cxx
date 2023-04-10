/*
Given the two integer values of a fraction, numerator and denominator, implement a function that returns the fraction in string format.
If the fractional part repeats, enclose the repeating part in parentheses.
Constraints
 denominator !=0;
 -2^31 <=numerator, denominator<=2^31

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string FractionToDecimal(int numerator, int denominator)
{
    string ans("");
    string final_ans("");
    if((numerator<0&&denominator>0) ||(numerator>0&&denominator<0))
        {
        ans.append("-");
        }
    long int d= abs(denominator);
        long int n=abs(numerator);
        
        ans = ans+std::to_string((long int)(n/d));
        std::unordered_map<long,int> m;
        long int remainder = n%d;
        if(remainder!=0)
        {
            ans.append(".");
            while(ans.size()<10001)
            {
                if(remainder ==0 ||m.find(remainder)!=m.end())
                {
                    break;
                }
                m[remainder] = ans.size();
                long int t= (remainder*10)/d;
                ans.append(std::to_string(t));
                remainder = (remainder*10)%d;
            }
            if(m.find(remainder)!=m.end())
            {
                final_ans = ans.substr(0,m[remainder]) 
                + "("+
                ans.substr(m[remainder])
                +")";
            }
            else{
                final_ans = ans;
            }
        }
        else
        final_ans = ans;
        return final_ans;
}

int main(int argc, char const *argv[])
{
     
     cout << FractionToDecimal( 2,4) << endl;
     cout << FractionToDecimal( 4,2) << endl;
     cout << FractionToDecimal( 5,333) << endl;
     cout << FractionToDecimal( 2,3) << endl;
     cout << FractionToDecimal( 47,18) << endl;
    return 0;
}
