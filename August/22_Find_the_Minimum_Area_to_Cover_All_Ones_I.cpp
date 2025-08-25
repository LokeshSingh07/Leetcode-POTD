// 3195. Find the Minimum Area to Cover All Ones I

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minRow = m;
        int minCol = n;
        int maxRow = -1;
        int maxCol = -1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow-minRow+1) * (maxCol-minCol+1);
    }
};