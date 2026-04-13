#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wtt) {
        // code here
        int ans = 0;
        
        vector<int> dp(W + 1, 0);
        
        for(int i = 0; i < val.size(); i++) {
            for(int wt = W; wt >=wtt[i]; wt--) {
                dp[wt] = max(dp[wt], val[i] + dp[wt-wtt[i]]);
            }
        }
        
        return dp[W];
    }
};