#include<bits/stdc++.h>
using namespace std;

//all the variation of these are same, 
//only difference in variation 2, in which any number of buy and sell can be ther, in that case, k will not be there, K condition chekking will be remove and from the dp, k will remove rest will be the same

class Solution {
public:
    int dp[1005][1005][2];
    int f(vector<int> &prices, int i, int k, bool on) {
        if(i==prices.size()) return 0;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        //avoid
        int ans = INT_MIN;
        ans = f(prices, i+1, k, on);
        //not avoid
        if(on) { //sell
            ans =  max(ans, prices[i] + f(prices, i+1, k-1, false));
        }else{
            if(k>0) { //buy
                ans = max(ans, f(prices, i+1, k, true)-prices[i]);
            }
        }
        return dp[i][k][on] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return f(prices, 0, k, false);
    }
};