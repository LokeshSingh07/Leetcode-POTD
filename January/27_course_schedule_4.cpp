// 1462. Course Schedule IV

class Solution {
public:
    bool DFS(int src, int dest, unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        visited[src] = true;
        if(src == dest) return true;

        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                if(DFS(nbr, dest, adj, visited)) return true;
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> ans;
        for(int i=0; i<Q; i++){
            int u = queries[i][0];
            int v =  queries[i][1];
            vector<bool> visited(numCourses, false);
            bool res = DFS(u, v, adj, visited);
            ans.push_back(res);
        }

        return ans;
    }
};