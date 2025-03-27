// 2685. Count the Number of Complete Components

class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, int src, vector<bool> &visi, int &v, int &e){
        visi[src] = true;
        v++;
        e += adj[src].size();

        for(auto nbr: adj[src]){
            if(!visi[nbr]){
                dfs(adj, nbr, visi, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<bool> visi(n, false);
        int result = 0;
        for(int i=0; i<n; i++){
            if(visi[i]) continue;

            int e=0;
            int v=0;
            dfs(adj, i, visi, v, e);

            if(v*(v-1) == e){
                result++;
            }
        }

        return result;
    }
};