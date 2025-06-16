// 1857. Largest Color Value in a Directed Graph

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n, 0);

        // prepare ajList, indegree
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // push node into queue with indegree 0
        vector<vector<int>> dp(n, vector<int>(26,0));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        // build the dp
        int ans=0;
        int nodesCount = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodesCount++;
            ans = max(ans, dp[u][colors[u]-'a']);

            for(int v: adj[u]){
                for(int i=0; i<26; i++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v]-'a' == i));
                }

                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(nodesCount < n) return -1;

        return ans;
    }
};