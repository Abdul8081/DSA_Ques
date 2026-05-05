class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        unordered_map<int, int> mp;
        int len = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k) {
                len = i + 1;
            }
            else if (mp.count(sum - k)) {
                len = max(len, i - mp[sum - k]);
            }
            if (!mp.count(sum)) {
                mp[sum] = i;
            }
        }
        return len;
    }
};