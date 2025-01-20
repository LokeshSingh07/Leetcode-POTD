// 407. Trapping Rain Water II

class Solution {
public:
    typedef pair<int, pair<int,int>> PP;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // process left most & right most column
        for(int row=0; row<m; row++){
            for(int col: {0, n-1}){
                pq.push({heightMap[row][col], {row,col}});
                visited[row][col] = true;
            }
        }

        // process the top most & bottom most row
        for(int col=0; col<n; col++){
            for(int row: {0, m-1}){
                pq.push({heightMap[row][col], {row,col}});
                visited[row][col] = true;
            }
        }

        // BFS wala logic
        int water = 0;
        while(!pq.empty()){
            PP p = pq.top();
            pq.pop();

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            // explore its nbr
            for(auto dir: directions){
                int newX = i + dir[0];
                int newY = j + dir[1];

                // check for safe state
                if(newX>=0 && newX<m && newY>=0 && newY<n && !visited[newX][newY]){
                    water += max(height-heightMap[newX][newY], 0);

                    pq.push({max(height, heightMap[newX][newY]), {newX,newY}});
                    visited[newX][newY] = true;
                } 
            }
        }

        return water;
    }
};