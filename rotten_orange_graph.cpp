#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> dir ={{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int refreshCount = 0;
        // {{r, c}, t}
        
        queue< pair< pair<int, int> , int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==1) {
                    refreshCount++;
                }
                if(mat[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int tm = 0;
        int countOne = 0;
        while(q.size()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            tm = max(tm, t);
            
            q.pop();
            
            for(int d=0; d<4; d++) {
                int cr = r + dir[d][0];
                int cc = c + dir[d][1];
                
                if(cr>=0 and cr<n and cc>=0 and cc<m and vis[cr][cc]!=2 and 
                mat[cr][cc]!=0 and mat[cr][cc]==1) {
                    vis[cr][cc] = 2;
                    q.push({{cr, cc},t+1});
                    mat[cr][cc] = 2;
                    countOne++;
                }
            }
        }
        
        // if(countOne != refreshCount) return -1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==1) return -1;
            }
        }
        
        return tm;
        
    }
};