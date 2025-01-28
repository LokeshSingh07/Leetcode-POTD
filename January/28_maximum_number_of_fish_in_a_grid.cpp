// 2658. Maximum Number of Fish in a Grid


// USing DFS
class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int DFS(vector<vector<int>> &grid, int i, int j){
        int ans = grid[i][j];
        grid[i][j] = 0;     // visited
        
        for(auto dir: dirs){
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]){
                ans += DFS(grid, newX, newY);
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    maxFish = max(maxFish, DFS(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};


// USing BFS
class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int BFS(vector<vector<int>> &grid,int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        int fish = grid[i][j];
        grid[i][j] = 0;         // mark visited;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            for(auto dir: dirs){
                int newX = p.first + dir[0];
                int newY = p.second + dir[1];

                if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]){
                    fish += grid[newX][newY];
                    grid[newX][newY] = 0;
                    q.push({newX, newY});
                }
            }
        }

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    maxFish = max(maxFish, BFS(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};