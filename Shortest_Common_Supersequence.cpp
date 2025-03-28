#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int m = str1.length(), n = str2.length();
            
            // Step 1: DP table for LCS
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            // Step 2: Construct SCS
            string result = "";
            int i = m, j = n;
            while (i > 0 || j > 0) {
                if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
                    result += str1[i - 1];
                    i--; j--;
                } else if (i > 0 && (j == 0 || dp[i][j] == dp[i - 1][j])) {
                    result += str1[i - 1];
                    i--;
                } else {
                    result += str2[j - 1];
                    j--;
                }
            }
            
            // Step 3: Reverse the result since we built it backwards
            reverse(result.begin(), result.end());
            return result;
        }  
    };