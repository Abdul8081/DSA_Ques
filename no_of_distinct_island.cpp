#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct hashVector { // this is the cucstom hash function whcih is not returing any things but we can use this in unordered set with the combination of the vector
        int operator()(const vector<pair<int,int>>& vec) const {
            return 1;
        }
    };
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        unordered_set< vector<pair<int, int>>,hashVector >st;
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]!=1 and grid[i][j]==1) {
                    vector<pair<int, int>> v;
                    
                    v.push_back({i-i, j-j});
                    vis[i][j] = 1;
                    
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while(q.size()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        
                        for(int d=0; d<4; d++) {
                            int cr = r + dir[d][0];
                            int cc = c + dir[d][1];
                            
                            if(cr>=0 and cr<n and cc>=0 and cc<m and !vis[cr][cc] and grid[cr][cc]==1){
                                vis[cr][cc] = 1;
                                v.push_back({cr-i, cc-j});
                                q.push({cr, cc});
                            }
                        }
                    }
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
