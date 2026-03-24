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


//Approach 2

class Solution {
public:
    int M = 1e9 + 7;
    typedef long long int ll;
    typedef pair<ll, ll> pp;
    int m; 
    int n;

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<pp>> p(m, vector<pp> (n)); // {maxVal, minVal}

        // filling in the first row
        p[0][0] = {grid[0][0], grid[0][0]};
        for(int c = 1; c < n; c++) {
            p[0][c].first = p[0][c-1].first * grid[0][c]; 
            p[0][c].second = p[0][c-1].second * grid[0][c];
        }

        // filling int the fist col
        for(int r = 1; r < m; r++) {
            p[r][0].first = p[r-1][0].first * grid[r][0];
            p[r][0].second = p[r-1][0].second * grid[r][0];
        }

        //filling in the internal cell

        for(int r = 1; r < m; r++) {
            for(int c = 1; c < n; c++) {
                ll el = grid[r][c];

                ll leftMax = p[r][c-1].first;
                ll leftMin = p[r][c-1].second;

                ll topMax = p[r-1][c].first;
                ll topMin = p[r-1][c].second;

                p[r][c].first  = max({el * leftMax, el* topMax, el * leftMin, el* topMin});
                p[r][c].second = min({el * leftMax, el* topMax, el * leftMin, el* topMin});
            }
        }

        auto [maxVal, _] = p[m-1][n-1];
        return maxVal < 0 ? -1 : maxVal % M;
        
    }
};