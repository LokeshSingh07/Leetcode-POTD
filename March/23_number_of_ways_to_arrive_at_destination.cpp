// 1976. Number of Ways to Arrive at Destination

class Solution {
public:
    typedef pair<long long,int> P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // Dijkstra
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> countPath(n,0);

        pq.push({0,0});     // {time, node}
        dist[0] = 0;
        countPath[0] = 1;

        while(!pq.empty()){
            long long time = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto nbr: adj[currNode]){
                int v = nbr.first;
                int t = nbr.second;
                
                if (time > dist[currNode]) continue;
                if(time+t < dist[v]){
                    dist[v] = time + t;
                    pq.push({dist[v], v});
                    countPath[v] = countPath[currNode];
                }
                else if(time + t == dist[v]){
                    countPath[v] = (countPath[v] + countPath[currNode]) % M;
                }
            }
        }

        return countPath[n-1];
    }
};