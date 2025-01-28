// 2127. Maximum Employees to Be Invited to a Meeting

class Solution {
public:
    int BFS(int start, unordered_map<int,vector<int>>&adj, vector<bool> &visited){
        queue<pair<int,int>> q;
        q.push({start, 0});
        int maxDist = 0;

        while(!q.empty()){
            auto [currNode,dist] = q.front();
            q.pop();

            for(auto nbr: adj[currNode]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push({nbr, dist+1});
                    maxDist = max(maxDist, dist+1);
                }
            }
        }
        return maxDist;
    }


    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int,vector<int>> adj;

        // reverse graph -> so that we can find the path length after traversal
        for(int i=0; i<n; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        // 
        int longestCycleCount = 0;
        int happyCoupleCount = 0;
        vector<bool> visited(n, false); 
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                unordered_map<int,int> mp;
                int currNode = i;
                int currNodeCount = 0;

                // cycle detect
                while(!visited[currNode]){
                    visited[currNode] = true;
                    mp[currNode] = currNodeCount;

                    int nextNode = favorite[currNode];
                    currNodeCount++;

                    // already visted
                    if(mp.count(nextNode)){
                        int cycleLength = currNodeCount - mp[nextNode];
                        longestCycleCount  = max(longestCycleCount, cycleLength);

                        if(cycleLength == 2){
                            // happy couple case
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCoupleCount += (2 + BFS(currNode,adj, visitedNodes) + BFS(nextNode, adj, visitedNodes));
                        }

                        break;
                    }
                    currNode = nextNode;
                }
            }
        }

        return max(longestCycleCount, happyCoupleCount);
    }
};