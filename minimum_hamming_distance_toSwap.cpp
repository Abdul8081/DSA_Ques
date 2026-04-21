class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int a){
        if(a==parent[a]) return a;

        return parent[a] = find(parent[a]);
    }

    void Union(int a, int b) {
        int x = find(a);
        int y = find(b);

        if(x == y) return;
        
        if(rank[x] < rank[y]) {
            swap(x, y);
        }
        parent[y] = x;
        rank[x]+=1;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < allowedSwaps.size(); i++) {
            int a = allowedSwaps[i][0];
            int b = allowedSwaps[i][1];
            Union(a, b);
        }

        unordered_map<int, unordered_map<int, int>> mp; // group -> {element, cnt}

        for(int i = 0; i < n; i++) {
            int f = find(i);
            mp[f][source[i]]++;
        }
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int f = find(i);

            if(mp[f][target[i]] > 0) mp[f][target[i]]--;
            else ans++;
        }
        return ans;
    }
};