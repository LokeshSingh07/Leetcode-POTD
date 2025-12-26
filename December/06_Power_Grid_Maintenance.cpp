// 3607. Power Grid Maintenance

class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, int node, int id, vector<int> &visited, vector<int> &nodeId, unordered_map<int,set<int>> &mp){
        visited[node] = true;
        nodeId[node] = id;
        mp[id].insert(node);

        for(auto &nbr: adj[node]){
            if(!visited[nbr]){
                dfs(adj, nbr, id, visited, nodeId, mp);
            }
        } 
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto connection: connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(c+1, false);
        vector<int> nodeId(c+1);
        unordered_map<int, set<int>> mp;

        for(int node=1; node<=c; node++){
            if(!visited[node]){
                int id = node;
                dfs(adj, node, id, visited, nodeId, mp);
            }
        }


        vector<int> result;
        for(auto &query: queries){
            int type = query[0];
            int node = query[1];
            int id = nodeId[node];

            if(type==1){
                if(mp[id].count(node)) result.push_back(node);
                else if(!mp[id].empty()) result.push_back(*mp[id].begin());
                else result.push_back(-1);
            }
            else{
                mp[id].erase(node);
            }
        }

        return result;
    }
};