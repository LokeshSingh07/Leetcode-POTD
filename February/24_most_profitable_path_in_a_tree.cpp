// 2467. Most Profitable Path in a Tree

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int t, vector<bool> &vis){
        vis[curr] = true;
        bobMap[curr] = t;
            
        if(curr == 0) return true;

        for(auto &nbr: adj[curr]){
            if(!vis[nbr]){
                if(DFSBob(nbr, t+1, vis)){
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }       

    void DFSAlice(int curr, int t, int income, vector<bool> &vis, vector<int>& amount){
        vis[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]){
            income += amount[curr];
        }
        else if(t == bobMap[curr]){
            income += amount[curr]/2;
        }

        if(curr!= 0 && adj[curr].size() == 1){
            aliceIncome = max(aliceIncome, income);
        }


        for(auto &nbr: adj[curr]){
            if(!vis[nbr]){
                DFSAlice(nbr, t+1, income, vis, amount);
            }
        }

    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;
        for(vector<int> &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // DFS for bob
        int time = 0;
        vector<bool> vis(n,false);
        DFSBob(bob, time, vis);


        int income = 0;
        vis.assign(n, false);
        DFSAlice(0, 0, income, vis, amount);

        return aliceIncome;
    }
};