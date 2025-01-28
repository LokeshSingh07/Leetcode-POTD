// 1765. Map of Highest Peak

class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> res(m, vector<int>(n,-1));      // also tracking the visited
        queue<P> q;

        // 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // BFS
        while(!q.empty()){
            int size = q.size();

            while(size--){
                P p = q.front();
                q.pop();

                int i = p.first;
                int j = p.second;

                // traverse its nbr -> U,R,D,L
                for(auto &dir: directions){
                    int newX = i + dir[0];
                    int newY = j + dir[1];

                    // check for safe state
                    if(newX>=0 && newX<m && newY>=0 && newY<n && res[newX][newY] == -1){
                        res[newX][newY] = res[i][j] + 1;
                        q.push({newX, newY});
                    }
                } 
            }
        }

        return res;
    }
};