// 2359. Find Closest Node to Given Two Nodes

class Solution {
public:
    void dfs(int u, vector<int> &edges, vector<int> &dist, vector<bool> &visited){
        visited[u] = true;
        int v = edges[u];

        if(v != -1 && !visited[v]){
            visited[v] = true;
            dist[v] = 1 + dist[u];
            dfs(v, edges, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(node1, edges, dist1, visited1);
        dfs(node2, edges, dist2, visited2);

        int minDistNode = -1;
        int minDist = INT_MAX;

        for(int i=0; i<n; i++){
            int maxDist = max(dist1[i], dist2[i]);
            if(minDist > maxDist){
                minDist = maxDist;
                minDistNode = i;
            }
        }

        return minDistNode;
    }
};