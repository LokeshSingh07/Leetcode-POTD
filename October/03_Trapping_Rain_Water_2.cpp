// 407. Trapping Rain Water II

class Solution {
public:
    typedef pair<int, pair<int,int>> PP;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<bool>> visited(m,vector<bool>(n, false));

        for(int r=0; r<m; r++){
            for(int c: {0,n-1}){
                pq.push({heightMap[r][c], {r,c}});
                visited[r][c] = true;
            }
        }

        for(int r: {0,m-1}){
            for(int c=0; c<n; c++){
                pq.push({heightMap[r][c], {r,c}});
                visited[r][c] = true;
            }
        }

        int trapWater = 0;
        while(!pq.empty()){
            PP P = pq.top();
            pq.pop();
            int height = P.first;
            int x = P.second.first;
            int y = P.second.second;

            for(auto dir: dirs){
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY]){
                    trapWater += max(height - heightMap[newX][newY], 0);
                    pq.push({max(height, heightMap[newX][newY]), {newX,newY}});
                    visited[newX][newY] = true;
                }
            }
        }

        return trapWater;
    }
};