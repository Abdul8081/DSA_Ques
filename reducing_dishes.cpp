#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[505][505];
    int t(vector<int>& s, int prevNo, int idx) {
        if(idx==s.size()) return 0;

        if(dp[prevNo][idx]!=-1) return dp[prevNo][idx];

        return dp[prevNo][idx] = max(t(s, prevNo, idx+1), prevNo*s[idx] + t(s, prevNo+1, idx+1));
    }

    int b(vector<int>& s) {
        int n = s.size();
        vector<vector<int> >dp(n+5, vector<int> (n+5, 0)); //prev_no, currentIndex
     
        for(int idx=n-1; idx>=0; idx--) {
            for(int prevNo = 1; prevNo<=n; prevNo++) {
                dp[prevNo][idx] = max(dp[prevNo][idx+1], prevNo*s[idx] + dp[prevNo+1][idx+1]);
            }
        }

        return dp[1][0];
    }

    int o(vector<int>& s) {
        int n = s.size();
        vector<int> curr(n+2, 0);
        vector<int> next(n+2, 0);
     
        for(int idx=n-1; idx>=0; idx--) {
            for(int prevNo = 1; prevNo<=n; prevNo++) {
                curr[prevNo] = max(next[prevNo], prevNo*s[idx] + next[prevNo+1]);
            }
            next = curr;
        }

        return next[1];
    }

    int fo(vector<int>& s) {
        //TC = O(N) + O(nlogn),SC=O(1) 
        int prefix = 0, res = 0;
        for(int idx=s.size()-1; idx>=0; idx--) {
            prefix+= s[idx];
            if(prefix>0) res += prefix;
            else break;
        }

        return res;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // memset(dp, -1, sizeof(dp));
        // return t(satisfaction, 1, 0);

        // return b(satisfaction);

        return fo(satisfaction);
    }
};