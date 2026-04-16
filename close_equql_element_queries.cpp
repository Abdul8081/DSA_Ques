class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;

        for(int &q: queries) {
            auto &v = mp[nums[q]];

            if(v.size() == 1) {
                res.push_back(-1);
                continue;
            }

            int m = v.size();

            // left pos
            int dis = INT_MAX;
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int left = v[(pos - 1 + m) % m];
            int d1 = abs(q - left);
            dis = min(dis, min(d1, (n - d1)));

            //right pos
            int right = v[(pos + 1) % m];
            int d2 = abs(q - right);
            dis = min(dis, min(d2, (n - d2)));

            res.push_back(dis);
        }

        return res;

    }
};
