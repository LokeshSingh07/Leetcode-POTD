// 684. Redundant Connection

class Solution {
public: 
    // DFS
    bool checkEdge(unordered_map<int,vector<int>> &adj, int src, int dest, vector<bool> &vis){
        vis[src] = true;
        if(src==dest) return true;

        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                if(checkEdge(adj, nbr, dest, vis)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            vector<bool> visited(m+1,0);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && checkEdge(adj, u, v, visited)) return edges[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};