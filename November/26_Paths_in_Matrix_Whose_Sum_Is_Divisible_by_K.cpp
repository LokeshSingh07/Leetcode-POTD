// 2435. Paths in Matrix Whose Sum Is Divisible by K

class Solution {
public:
    int m,n;
    int M = 1e9+7;
    vector<vector<vector<int>>> t;

    int solve(vector<vector<int>> &grid, int r, int c, int currSum, int &k, vector<vector<vector<int>>> &t){
        if(r>=m || c>=n) return 0;
        if(r==m-1 && c==n-1){
            return (currSum + grid[r][c]) % k == 0;
        }

        if(t[r][c][currSum] != -1) return t[r][c][currSum];

        int right = solve(grid, r, c+1, (currSum+grid[r][c])%k, k, t);
        int down = solve(grid, r+1, c, (currSum+grid[r][c])%k, k, t);
        
        return t[r][c][currSum] = (down + right) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(grid, 0, 0, 0, k, t);
    }
};