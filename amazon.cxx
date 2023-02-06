//using namespace std;

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EditDistance {

public:
  int findMinOperations(const string &s1, const string &s2) {
    
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,INT_MAX));

    dp[0][0] =0;

    for ( int i = 0 ; i < s1.size();++i) {
        for ( int j = 0 ; j < s2.size();++j) {
            if (s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                dp[i+1][j+1] = min(dp[i][j+1], min( dp[i+1][j], dp[i][j])) +1;
            }
        }
    }

    return dp[s1.size()][s2.size()];
  }
};

int main(int argc, char *argv[]) {
  EditDistance *editDisatnce = new EditDistance();
  cout << editDisatnce->findMinOperations("bat", "but") << endl;
  cout << editDisatnce->findMinOperations("abdca", "cbda") << endl;
  cout << editDisatnce->findMinOperations("passpot", "ppsspqrt") << endl;

  delete editDisatnce;
}