class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> bits(31, 0);
        for(int el: nums) {
            int idx = 0;
            while(el) {
                if(el & 1) bits[idx]++;
                el >>= 1;
                idx++;
            }
        }
        int mul = 1;
        int ans = 0;
        for(int i = 0; i < 31; i++) {
            if(bits[i] >= k) {
                ans += mul;
            }
            mul <<= 1;
        }

        return ans;
    }
};