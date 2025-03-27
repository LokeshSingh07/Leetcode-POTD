// 3108. Minimum Cost Walk in Weighted Graph

class Solution {
public:
    vector<int> parent;
    // DSU
    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int u, int v){
        parent[v]= u;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n);

        // initialize
        for(int i=0; i<n; i++){
            parent[i] = i;
            cost[i] = -1;
        }

        // precompute
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                cost[parent_u] &= cost[parent_v];
                Union(parent_u, parent_v);
            }
            cost[parent_u] &= w;
        }

        vector<int> ans;
        for(auto q: query){
            int u = q[0];
            int v = q[1];
            
            int p_u = find(u);
            int p_v = find(v);
            if(u == v) ans.push_back(0);
            if(p_u == p_v) ans.push_back(cost[p_u]);
            else ans.push_back(-1);
        }

        return ans;
    }
};