#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[1005][1005];
    int t(vector<int>& arr, int curr, int prev){
        if(curr == arr.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int take = 0;
        if(prev==-1 or arr[curr] > arr[prev]) take = 1+t(arr, curr+1, curr);
        int notTake = 0;
        notTake = t(arr, curr+1, prev);
        
        return dp[curr][prev+1] = max(take, notTake);
    }
    
    int b(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev==-1 or arr[curr] > arr[prev]) take = 1+dp[curr+1][curr+1];
                int notTake = 0;
                notTake = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
    
    int o(vector<int>& arr){
        int n = arr.size();
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--){
                int take = 0;
                if(prev==-1 or arr[curr] > arr[prev]) take = 1+nextRow[curr+1];
                int notTake = 0;
                notTake = nextRow[prev+1];
                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int optimal(vector<int> & arr){
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);
        
        for(int i=1; i<n; i++) {
            if(arr[i] > ans.back()) ans.push_back(arr[i]);
            else{
                //calculationg lower bound by binary search
                int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[idx] = arr[i];
            }
        }
        return ans.size();
    }
    int lis(vector<int>& arr) {
        // code here
        // memset(dp, -1, sizeof(dp));
        // return t(arr, 0, -1);
        
        // return b(arr);
        // return o(arr);
        
        return optimal(arr);
    }
};