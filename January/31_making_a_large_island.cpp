// 827. Making A Large Island

// Method1: Brute force
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    int DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || i>=n || j<0 || j>=n || !grid[i][j] || visited[i][j]) return 0;

        visited[i][j] = true;
        int size = 1;
        for(auto &dir: dirs){
            int newX = dir[0] + i;
            int newY = dir[1] + j;
            size += DFS(grid, newX, newY, visited);   
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    grid[i][j] = 1;

                    // find the largest area after changing 1 to 0
                    int largestArea = 0;
                    vector<vector<bool>> visited(n, vector<bool>(n,false));
                    for(int x=0; x<n; x++){
                        for(int y=0; y<n; y++){
                            if(grid[x][y] && !visited[x][y]){
                                largestArea = max(largestArea, DFS(grid, x, y, visited));
                            }
                        }
                    }

                    grid[i][j] = 0;
                    maxArea = max(maxArea, largestArea);
                }
            }
        }

        return maxArea==0 ? n*n : maxArea;
    }
};

// Method2: Better Brute force
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    int DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || i>=n || j<0 || j>=n || !grid[i][j] || visited[i][j]) return 0;

        visited[i][j] = true;
        int size = 1;
        for(auto &dir: dirs){
            int newX = dir[0] + i;
            int newY = dir[1] + j;
            size += DFS(grid, newX, newY, visited);   
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;

        // precompute
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    maxArea = max(maxArea, DFS(grid, i, j, visited));
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    grid[i][j] = 1;

                    // find the largest area after changing 1 to 0
                    visited = vector<vector<bool>>(n, vector<bool>(n,false));
                    int largestArea = DFS(grid, i, j, visited);

                    grid[i][j] = 0;
                    maxArea = max(maxArea, largestArea);
                }
            }
        }

        return maxArea==0 ? n*n : maxArea;
    }
};


// Method3: Optimised
class Solution {
public:
    int n, unique_id=2;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int DFS(vector<vector<int>> &grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != 1) return 0;
        grid[i][j] = unique_id;
        int size = 1;
        
        for(auto dir: dirs){
            int newX = i + dir[0];
            int newY = j + dir[1];
            
            size += DFS(grid, newX, newY);
        }

        return size;
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int,int> mp;          // {unique_id, size}
        int maxArea = 0;
        
        // step1: compute size and assign unique_if
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int size = DFS(grid, i, j);
                    mp[unique_id] = size;
                    maxArea = max(maxArea, size);
                    unique_id++;
                }
            }
        } 


        // step2: change 0 to 1
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    unordered_set<int> uniqueIds;
                    for(auto dir: dirs){
                        int newX = i + dir[0];
                        int newY = j + dir[1];

                        if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY] > 1){
                            uniqueIds.insert(grid[newX][newY]);
                        }
                    }
                    int overallSize = 1;
                    for(auto it : uniqueIds){
                        overallSize += mp[it];
                    }
                    maxArea = max(maxArea, overallSize);
                }
            }
        }


        return maxArea == 0 ? n*n : maxArea ;
    }
};