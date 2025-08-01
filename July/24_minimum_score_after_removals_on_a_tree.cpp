// 2322. Minimum Score After Removals on a Tree

class Solution {
public:
    void DFS(unordered_map<int,vector<int>> &adj, vector<int> &nums, int node, int parent, int &timer, vector<int> &inTime, vector<int> &outTime, vector<int> & xorSubTree){
        xorSubTree[node] = nums[node];
        inTime[node] = timer;
        timer++;

        for(auto nbr: adj[node]){
            if(parent != nbr){
                DFS(adj, nums, nbr, node,timer, inTime, outTime, xorSubTree);
                xorSubTree[node] ^= xorSubTree[nbr];
            }
        }

        outTime[node] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int> &inTime, vector<int> &outTime){
        return ((inTime[u] <= inTime[v]) && (outTime[v] <= outTime[u]));
    }

    int getScore(int xor1, int xor2, int xor3){
        int maxi = max({xor1, xor2, xor3});
        int mini = min({xor1, xor2, xor3});
        return maxi - mini;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> xorSubTree(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;

        DFS(adj, nums, 0, -1, timer, inTime, outTime, xorSubTree);


        int result = INT_MAX;
        for(int u=1; u<n; u++){
            for(int v=u+1; v<n; v++){
                int xor1=0, xor2=0, xor3=0;

                if(isAncestor(u, v, inTime, outTime)){
                    xor1 = xorSubTree[v];
                    xor2 = xorSubTree[u] ^ xor1;
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }
                else if(isAncestor(v, u, inTime, outTime)){
                    xor1 = xorSubTree[u];
                    xor2 = xorSubTree[v] ^ xor1;
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }
                else{
                    xor1 = xorSubTree[u];
                    xor2 = xorSubTree[v];
                    xor3 = xorSubTree[0] ^ xor1 ^ xor2;
                }

                result = min(result, getScore(xor1, xor2, xor3));
            }
        }


        return result;
    }
};