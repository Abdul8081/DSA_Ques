class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> store;

            int top = layer, left = layer; 
            int right = n - 1 - layer, bottom = m - 1 - layer;

            //top
            for (int j = top; j <= right; j++) {
                store.push_back(grid[top][j]);
            }

            //right
            for (int i = top + 1; i <= bottom - 1; i++) {
                store.push_back(grid[i][right]);
            }

            //bottom
            for (int j = right; j >= left; j--) {
                store.push_back(grid[bottom][j]);
            }

            //left
            for (int i = bottom - 1; i >= top + 1; i--) {
                store.push_back(grid[i][left]);
            }

            int len = store.size();
            int rot = k % len;

            vector<int> rotated(len);

            //rotated start first index
            for (int i = 0; i < len; i++)  {
                rotated[i] = store[(i + rot) % len];
            }

            //filling in rotated array
            int idx = 0;
            //top
            for (int j = top; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            //right
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = rotated[idx++];
            }

            //bottom
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            //left
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};