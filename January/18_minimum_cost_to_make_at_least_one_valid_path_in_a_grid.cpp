// 1368. Minimum Cost to Make at Least One Valid Path in a Grid


// TLE
class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m,n;

    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int cost){   
        if(i==m-1 && j==n-1) return cost;

        visited[i][j] = true;

        // explore all possible ways
        int minCost = INT_MAX;

        for(int d=0; d<3; d++){
            int newX = i + directions[d][0];
            int newY = j + directions[d][1];

            // check for safe
            if(newX>=0 && newX<=m-1 && newY>=0 && newY<=n-1 && !visited[newX][newY]){
                int directionCost = 0;
                int gridDirection = grid[i][j];
                if((gridDirection == 1 && d != 0) || (gridDirection == 2 && d != 1) ||(gridDirection == 3 && d != 2) || (gridDirection == 4 && d != 3)){
                    directionCost = 1;
                }

                int newCost = cost + directionCost;
                minCost = min(minCost, DFS(newX, newY, grid, visited, newCost));
            }
        }


        visited[i][j] = false;

        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        int cost = 0;
        return DFS(0, 0, grid, visited, cost);
    }
};



// Heap
class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;   // in_heap
        vector<vector<int>> result (m, vector<int>(n, INT_MAX));

        // Dijkstra
        pq.push({0,0,0});
        result[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int i= curr[1];
            int j = curr[2];

            for(int dir=0; dir<=3; dir++){
                int newX = i + directions[dir][0];
                int newY = j + directions[dir][1];

                if(newX>=0 && newX<m && newY>=0 && newY<n){
                    int gridDir = grid[i][j];
                    int dirCost = (gridDir-1 != dir) ? 1 : 0; 

                    int newCost = currCost + dirCost;

                    if(newCost < result[newX][newY]){
                        result[newX][newY] = newCost;
                        pq.push({newCost, newX, newY});
                    }
                }
            }
        }
        
        return result[m-1][n-1];
    }
};
