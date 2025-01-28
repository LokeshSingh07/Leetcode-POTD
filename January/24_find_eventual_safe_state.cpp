// 802. Find Eventual Safe States

class Solution {
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsTrack){
        visited[src] = true;
        dfsTrack[src] = true;

        for(auto nbr: graph[src]){
            if(!visited[nbr] && dfs(nbr, graph, visited, dfsTrack)) return true;
            else if(dfsTrack[nbr]) return true;
        }

        dfsTrack[src] = false;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> dfsTrack(n, false);

        for(int node=0; node<n; node++){
            if(!visited[node]) dfs(node, graph, visited, dfsTrack);
        }
        

        vector<int> safeNode;
        for(int i=0; i<n; i++){
            if(!dfsTrack[i]) safeNode.push_back(i);
        }

        return safeNode;
    }
};