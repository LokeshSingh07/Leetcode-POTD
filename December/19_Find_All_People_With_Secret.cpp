// 2092. Find All People With Secret

class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,vector<P>> adj;

        for(auto &meeting: meetings){
            int x = meeting[0];
            int y = meeting[1];
            int t = meeting[2];
            adj[x].push_back({y, t});
            adj[y].push_back({x, t});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        dist[firstPerson] = 0;

        queue<P> q;
        q.push({0,0});
        q.push({firstPerson, 0});


        while(!q.empty()){
            auto [person, time] = q.front();
            q.pop();

            if(time > dist[person]) continue;

            for(auto &[p,t]: adj[person]){
                if(t>=time && dist[p]>t){
                    dist[p] = t;
                    q.push({p, t});
                }
            }
        }


        vector<int> result;
        for(int i=0; i<n; i++){
            if(dist[i] != INT_MAX){
                result.push_back(i);
            }
        }

        return result;
    }
};