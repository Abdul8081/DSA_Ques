#include<bits/stdc++.h>
using namespace std;

//this is the topological sort using both dfs and kahn's algorithms
// basically topolofical sort is a type of sorting which is performed for the only 
// the acyclic directed graph(DAF) and in that we have to give a liner ording of the element in such a way that if there is edge 
// between the node u and v then in the linear odering of the ans u will be before v
class Solution {
    private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int>&st) {
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) {
                dfs(it, vis, adj, st);
                
            }
            
        }
        
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // this is code for the toposorting with dfs
        // vector<vector<int> > adj(V);
        // for(int i=0; i<edges.size(); i++) {
        //     adj[edges[i][0]].push_back(edges[i][1]);
        // }
        
        // stack<int> st;
        // vector<int> vis(V,0);
        
        // for(int i=0; i<V; i++) {
        //     if(!vis[i]) {
        //         // dfs(i, vis, adj, st);
        //         bfs(i, vis, adj, st);
        //     }
        // }
        
        // vector<int> ans;
        // while(st.size()){
            
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
        
        
        // this is the code for the sorting using kahn's algo
        vector<vector<int> > adj(V);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> indegree(V);
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(q.size()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
        
    }        
};