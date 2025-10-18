// 778. Swim in Rising Water

class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int n;

    bool isPossibleToReach(vector<vector<int>> &grid, int i, int j, int &maxi, vector<vector<bool>> &visited){
        if(i==n-1 && j==n-1) return true;
        visited[i][j] = true;

        for(auto dir: dirs){
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(newX >= 0 && newX < n && newY >= 0 && newY < n && 
                !visited[newX][newY] && grid[newX][newY] <= maxi){
                if(isPossibleToReach(grid, newX, newY, maxi, visited)) return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int result = -1;
        int s=grid[0][0], e=n*n-1;

        while(s <= e){
            int mid = s+(e-s)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(isPossibleToReach(grid, 0, 0, mid, visited)){
                result = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return result;
    }
};