#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compute(string s1, string s2, int i , int j , vector<vector<int>>& dp) {
	cout << " i: " << i << " j : " << j << endl;
	if ( i >= s1.length() && j >= s2.length()) return 0;

    if ( i>=s1.length()) { return  s2.length()-j;}
	if (j >= s2.length()) { return s1.length()-i;}

	if (dp[i][j]!=-1) return dp[i][j];

	if (s1[i-1] == s2[j-1]) { 
		dp[i][j] = compute(s1, s2, i+1, j+1, dp);
	} else {
		int v1 = compute(s1, s2, i+1, j+1,dp);
		int v2 = compute(s1, s2, i, j+1, dp);
		int v3 = compute(s1, s2, i+1,j, dp);
		// find the min
		dp[i][j] = min(v1, min(v2, v3))+1;
	}
	return dp[i][j];
}

int LevenshteinDistance(string str1, string str2){
	vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1,-1));
	dp[0][0]=0;
    compute(str1, str2,1,1,dp);


	return dp[str1.length()-1][str2.length()-1];
}


int main() {
    std::cout << LevenshteinDistance("apple", "orange") << endl;
    return 0;
}