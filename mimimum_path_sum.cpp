class Solution {
public:
    int m;
    int n;
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i == m - 1) {
            // can go only right;
            return dp[i][j] = grid[i][j] + solve(i, j + 1, grid);
        }
        else if(j == n-1) {
            // can go only down
            return dp[i][j] = grid[i][j] + solve(i + 1, j, grid);
        }
        else {
            // can right && down both
            return dp[i][j] = grid[i][j] + min(solve(i+1, j, grid), solve(i, j+1, grid));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, grid);
    }
};