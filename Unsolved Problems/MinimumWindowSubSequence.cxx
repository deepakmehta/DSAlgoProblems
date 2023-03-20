/*
Given strings str1 and str2, find the minimum (contiguous) substring subStr of str1,
such that every character of str2 appears in subStr in the same order as it is present in str2.

* If there is no window in str1 that covers all characters in str2, return an empty string.
* If there are multiple minimum-length windows, return the one with the leftmost starting index.

Constraints:
 1 <=str1.length <=2*10^3
 1<=str2.length<100
 str1 and str2 consist of UpperCase and LowerCase English letters

*/

#include <climits>
#include <string>
using namespace std;

string MinWindow(string str1, string str2)
{
    
    return "";
}

int main(int argc, char const *argv[])
{
    cout << MinWindow("abcdebdde", "bde") << endl;
    cout << MinWindow("fgrqsqsnodwmxzkzxwqegkndaa", "kzed") << endl;
    cout << MinWindow("michmznaitnjdnjkdsnmichmznait", "michmznait") << endl;
    cout << MinWindow("afgegrwgwga", "aa") << endl;
    cout << MinWindow("abababa", "ba") << endl;
    return 0;
}
