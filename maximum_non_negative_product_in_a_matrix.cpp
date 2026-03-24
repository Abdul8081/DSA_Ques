class Solution {
public:
    int M = 1e9 + 7;
    typedef long long int ll;
    typedef pair<ll, ll> pp;
    int m; 
    int n;

    vector<vector<pp>> dp;

    pp solve(int i, int j, vector<vector<int>>& grid) {
        if(i == m-1 && j==n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return dp[i][j];
        }

        
        ll minVal = LLONG_MAX;
        ll maxVal = LLONG_MIN;
        int el = grid[i][j];

        //right
        if(j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);
            
            minVal = min({minVal, el * rightMax, el * rightMin});
            maxVal = max({maxVal, el * rightMax, el * rightMin});

        }

        //down
        if(i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, grid);

            minVal = min({minVal, el * downMax, el * downMin});
            maxVal = max({maxVal, el * downMax, el * downMin});
        }

        return dp[i][j] = {maxVal, minVal};


    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.clear();

        dp.resize(m+1, vector<pp> (n+1, {LLONG_MIN, LLONG_MAX}));

        auto [ansMax, ansMin] = solve(0, 0, grid);

        return ansMax < 0 ? -1 : ansMax % M;
    }
};