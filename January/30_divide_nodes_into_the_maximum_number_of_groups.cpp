// 2493. Divide Nodes Into the Maximum Number of Groups

class Solution {
public:
    bool isBipartite(unordered_map<int,vector<int>> &adj, int src, vector<int> &colors, int currColor){
        colors[src] = currColor;

        for(auto &nbr: adj[src]){
            if(colors[nbr] == colors[src]) return false;

            if(colors[nbr] == -1){
                if(isBipartite(adj, nbr, colors, 1-currColor) == false) return false;
            }
        }
        return true;
    }

    int bfs(unordered_map<int,vector<int>>&adj, int src, int n){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        int level = 1;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr = q.front();
                q.pop();

                for(auto &nbr: adj[curr]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            level++;
        }

        return level-1;
    }

    int getMaxFromEachComp(unordered_map<int,vector<int>> &adj, int src, vector<bool> &visited, vector<int> &levels){
        int maxGrp = levels[src];
        visited[src] = true;

        for(auto &nbr: adj[src]){
            if(!visited[nbr]){
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, nbr, visited, levels));
            }
        }
        return maxGrp;
    }



    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Bipartite graph
        vector<int> colors(n, -1);
        for(int node=0; node<n; node++){
            if(colors[node] == -1){
                if(isBipartite(adj, node, colors, 1) == false) return -1;
            }
        }

        // BFS from each node to find maxLevel
        vector<int> levels(n,0);
        for(int node=0; node<n; node++){
            levels[node] = bfs(adj, node, n);
        }


        // find maxGrp in each disconnected graph
        int maxGrpEacHComp = 0;
        vector<bool> visited(n, false);
        for(int node=0; node<n; node++){
            if(!visited[node]){
                maxGrpEacHComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        return maxGrpEacHComp;
    }
};