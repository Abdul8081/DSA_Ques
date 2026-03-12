// User function Template for C++
class DSU {
public:
    vector<int> parent, rank;
    DSU(int size){
        rank.resize(size, 0);
        parent.resize(size);
        
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x){
        int root = parent[x];
        
        if(x == root) return x;
        
        if(x != root) {
            return parent[x] = find(parent[x]);
        }
        return root;
    }
    
    void unite(int x,int y){
        int xRoot = find(x);
        
        int yRoot = find(y);
        
        if(rank[xRoot] < rank[yRoot]){
            parent[xRoot] = yRoot;
        }
        else if(rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        }
        else{
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b){
    // sorting in increasing order based on 3rd value.
    return a[2] < b[2];
}

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        // sorting based on the edges. 
        sort(edges.begin(), edges.end(), cmp);
        
        DSU dsu(V);
        
        int nodeCnt = 0, weightSum = 0;
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if(dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                weightSum += w;
                if(++nodeCnt == V-1) break;
            }
            
        }
        return weightSum;
        
    }
};





